#include <iostream>
#include <vector> 
#include <queue> 
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)
#define ii pair<int, int> 

using namespace std;

int n, m, s, t, a, b, c, d[MAXN];
priority_queue<ii> pq;
vector<ii> grafo[MAXN];


int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s >> t;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	d[s] = INF;
	pq.push({d[s], s});
	while (!pq.empty())
	{
		auto[menor, u] = pq.top(); pq.pop();
		if (d[u] > menor) continue;

		for (auto[v, w] : grafo[u])
		{
			if (d[v] < min(d[u], w))
			{
				d[v] = min(d[u], w);
				pq.push({d[v], v});
			}
		}
	}

	cout << (d[t] ? d[t] : -1) << endl;

}
