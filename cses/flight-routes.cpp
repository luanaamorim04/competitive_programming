#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int>
#define int long long
#define iii tuple<int, int, int> 

using namespace std;

int n, m, k, a, b, c;
vector<ii> grafo[MAXN];
multiset<int> dist[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int32_t main()
{
	cin >> n >> m >> k;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	dist[1].insert(0);
	pq.push({0, 1});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (-d < *dist[u].begin()) continue;

		for (auto[v, w] : grafo[u])
		{
			if (dist[v].size() < k) 
			{
				dist[v].insert(-(d + w));
				pq.push({d + w, v});
			}
			else if (-(*dist[v].begin()) > d + w)
			{
				auto it = dist[v].begin();
				dist[v].erase(it);
				dist[v].insert(-(d + w));
				pq.push({d + w, v});
			}
		}
	}

	vector<int> r;
	for (auto x : dist[n]) r.push_back(x);
	for (int i = r.size() - 1; i >= 0; i--) cout << -r[i] << ' ';
	cout << endl;

}
