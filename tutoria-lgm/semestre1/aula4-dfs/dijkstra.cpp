#include <iostream> 
#include <queue>
#include <vector> 
#define ii pair<int, int> 
#define MAXN (int) (1e5 + 10)

using namespace std;

priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ii> grafo[MAXN];
int dist[MAXN], n, m, a, b, c;

int main()
{

	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}
	
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (dist[u] < d) continue;

		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		printf("dist[%d] = %d\n", i, dist[i]);
}
