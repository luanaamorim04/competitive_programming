#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e16)  
#define ii pair<int, int>

using namespace std;

int n, m, a, b, c, dist[MAXN], resp[MAXN];
vector<ii> grafo[MAXN], rev[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int32_t main()
{			

	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		rev[b].push_back({a, c});
	}

	for (int i = 2; i <= n; i++) dist[i] = resp[i] = INF;
	pq.push({0, 1});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		// cout << u << ' ' << dist[u] << endl;

		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	for (int i = 2; i <= n; i++)
		rev[1].push_back({i, dist[i]});

	pq.push({0, 1});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > resp[u]) continue;

		for (auto[v, w] : rev[u])
		{
			if (resp[v] > resp[u] + w)
			{
				resp[v] = resp[u] + w;
				pq.push({resp[v], v});
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << ((resp[i] == INF) ? -1 : resp[i]) << ' ';
	
	cout << endl;
}