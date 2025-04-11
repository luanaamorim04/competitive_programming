#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<array<int, 2> > grafo[MAXN];
map<ii, int> arr, del;
int n, m, a, b, c, grau[MAXN], pos[MAXN], freq[MAXN];

vector<int> eulerian_path(int s, int n, int m)
{
	vector<int> resp;
	for (int i = 1; i <= n; i++)
	{
		if (grau[i]) return resp;
		sort(all(grafo[i]));
	}

	stack<int> pilha;
	pilha.push(s);
	while (!pilha.empty())
	{
		int u = pilha.top();
		if (pos[u] >= grafo[u].size())
		{
			pilha.pop();
			resp.push_back(u);
			continue;
		}

		for (; pos[u] < grafo[u].size(); pos[u]++)
		{
			auto &v = grafo[u][pos[u]];
			if (del[{u, v[0]}] == 0) continue;
			del[{u, v[0]}]--;
			pilha.push(v[0]);
			break;
		}
	}

	if (resp.size() != m+2) resp.clear();
	return resp;
}

int32_t main()
{_
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		del[{a, b}]++;
		grafo[a].push_back({b, (int)grafo[b].size()});
		grau[a]++;
		grau[b]--;
	}

	grafo[n].push_back({1, -1});
	del[{n, 1}]++;
	grau[1]--;
	grau[n]++;

	vector<int> resp = eulerian_path(1, n, m);
	if (resp.size() == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	reverse(all(resp));
	int ok = 0;
	for (int i = 0; i < resp.size(); i++)
		if (resp[i] == n && resp[i+1] == 1) ok = i;


	for (int i = ok+1; i < resp.size(); i++)
		cout << resp[i] << ' ';
	for (int i = 1; i < ok; i++)
	{
		cout << resp[i] << ' ';
	}
	cout << n << endl;
}
