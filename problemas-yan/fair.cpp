#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9)
#define MAXN (int) (2e5 + 5)
#define MAXM 100
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, s, arr[MAXN], a, b, vis[MAXN];
vector<int> grafo[MAXN], tipo[MAXM];
int dist[MAXN][MAXM];

int main()
{_
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		tipo[arr[i]].push_back(i);
	}

	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	queue<par> fila;
	for (int i = 1; i <= k; i++)
	{
		// dbug(i);
		for (int vrtc : tipo[i])
			fila.push({vrtc, 0});

		while (!fila.empty())
		{
			auto[u, p] = fila.front(); fila.pop();
			if (vis[u] == i) continue;
			vis[u] = i;
			dist[u][i] = dist[p][i] + 1;
			
			for (int v : grafo[u])
			{
				if (vis[v] != i)
					fila.push({v, u});
			}
		}
		//cout << endl;
	}

	for (int u = 1; u <= n; u++)
	{
		vector<int> v;
		for (int i = 1; i <= k; i++)
			v.push_back(dist[u][i]-1);

		sort(all(v));
		ll resp = 0;
		for (int i = 0; i < s; i++)
			resp += v[i];

		cout << resp << ' ';
	}
	cout << endl;
}















