//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define INF 1e15
#define ii pair<long long, long long>
#define all(x) x.begin(), x.end()
#define ll long long
#define int ll

using namespace std;

ll n, m, t, a, b, c, dist[MAXN], vis[MAXN];

int solve(int n, int m)
{
	vector<ii> grafo[MAXN];
	queue<ii> fila;
	for (int i = 1; i <= n; i++)
		dist[i] = INF, vis[i] = 0;

	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, -c});
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		dist[i] = 0;
		fila.push({i, 0});
		while (!fila.empty())
		{
			auto[u, d] = fila.front(); fila.pop();
			vis[u] = 1;
			for (auto[v, w] : grafo[u])
			{
				if (dist[v] == INF)
				{
					dist[v] = d + w;
					fila.push({v, dist[u] + w});
				} 
				else if (dist[v] != dist[u] + w) return 0;
			}
		}
	}

	return 1;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << (solve(n, m) ? "YES" : "NO") << endl;
	}
}	
