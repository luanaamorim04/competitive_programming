#include <iostream>
#include <bits/stdc++.h>
#include <vector> 
#include <queue> 
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int>

using namespace std;

int n, m, a, b, c, dist[MAXN], curr;
vector<ii> grafo[MAXN];
priority_queue<iii> pq;

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	for (int i = 2; i <= n; i++) dist[i] = -INF;

	pq.push({0, 0, 1});
	while (!pq.empty())
	{
		auto[d, p, u] = pq.top(); pq.pop();
		if (d < dist[u]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (v == p) continue;
			if (dist[v] < d + w)
			{
				dist[v] = d + w;
				pq.push({dist[v], u, v});
			}
		}

		curr++;
		if (curr > 5e6) 
		{
			cout << -1 << endl;
			return 0;
		}
	}

	cout << dist[n] << endl;
}
