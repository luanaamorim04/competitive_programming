#include <iostream>
#include <map>
#include <vector> 
#include <queue>
#define MAXN (int) (2e5 + 10)
#define ii pair<int, int>
#define iii tuple<int, int, int>

using namespace std;

int e, s, n, m, k, arr[MAXN], a, b, c, curr, dist[MAXN];
vector<iii> arestas;
map<ii, vector<int> > cores;
map<ii, int> vis;
vector<ii> grafo[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > pq;

void dfs(int u, int a, int p)
{	
	grafo[p].push_back({u, arr[a]});
	grafo[u].push_back({p, arr[a]});
	vis[{u, a}] = 1;
	for (int v : cores[{u, a}])
	{
		if (vis[{v, a}]) continue;
		dfs(v, a, p);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> arr[i];

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		cores[{a, c}].push_back(b);
		cores[{b, c}].push_back(a);
		arestas.push_back({a, b, c});
	}

	cin >> s >> e;
	
	curr = n + 1;
	for (int i = 0; i < m; i++)
	{
		auto[u, v, t] = arestas[i];
		if (!vis[{u, t}]) dfs(u, t, curr++);
	}

//	for (int i = 1; i <= curr; i++)
//	{
//		cout << i << ": ";
//		for (auto [a, b] : novo[i])
//			cout << a << ' ';
//		cout << endl;
//	}

	for (int i = 1; i <= curr; i++) dist[i] = 1e9 + 10;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;

		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	cout << (dist[e] == 1e9 + 10? -1 : dist[e]/2) << endl;
}
