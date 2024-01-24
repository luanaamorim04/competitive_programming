#include <bits/stdc++.h>
#define MAXN (int) (1e5 + 10)
#define all(x) x.begin(), x.end()

using namespace std;

int T, n, m, a, b, c, pai[MAXN], resp[MAXN], tam[MAXN];
vector<int> grafo[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b, int c)
{
	a = find(a), b = find(b);
	if (tam[a] < tam[b]) swap(a, b);
	resp[a] += c*tam[b];
	resp[b] += c*tam[a] - resp[a];
	tam[a] += tam[b];
	pai[b] = a;
	grafo[a].push_back(b);
}

void dfs(int u, int p, int ans)
{
	resp[u] += ans;
	for (int v : grafo[u])
	{
		dfs(v, u, resp[u]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	freopen("road.in", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			grafo[i].clear();
			pai[i] = i;
			tam[i] = 1;
			resp[i] = 0;
		}	

		vector<tuple<int, int, int> > arr;
		while (m--)
		{
			cin >> a >> b >> c;
			arr.push_back({c, a, b});
		}	
		
		sort(all(arr));
		for (auto[w, u, v] : arr)
		{	
			if (find(u) == find(v)) continue;
			join(u, v, w);
		}

		dfs(find(1), 0, 0);
		cout << "Case " << t << ":\n";
		for (int i = 1; i <= n; i++)
			cout << resp[i] << "\n";
	}
}
