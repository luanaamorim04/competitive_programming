#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define int long long
#define MAXN (size_t) (2e3 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, k, s, t, a, b, c;
int dist[MAXN], last[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ii> grafo[MAXN];
map<ii, int> arr;

int dijkstra(int x)
{
	for (int i = 0; i < n; i++) dist[i] = 1e9 + 10;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto[w, v] : grafo[u])
		{
			if (!w) w = x;
			if (dist[v] > dist[u] + w)
			{
				last[v] = u;
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist[t];
}

int caminho(int x, int j)
{
	if (x > k && j == 1) return -1;
	int cnt = x-k;
	int curr = t, tam = 0;
	while (curr != s)
	{
		int nxt = last[curr];
		int &peso = arr[{min(curr, nxt), max(curr, nxt)}];
		tam += (peso ? peso : j);
		if (cnt && !peso) --cnt, peso = j - 1, --tam;
		curr = nxt;

	}
	return tam;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> s >> t;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({c, b});
		grafo[b].push_back({c, a});
		arr[{min(a, b), max(a, b)}] = c;
	}

	if (dijkstra(0) == 1e9 + 10) 
	{
		cout << "NO" << endl;
		return 0;
	}

	int ini = 1, meio, fim = 1e9;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (dijkstra(meio) >= k) fim = meio - 1;
		else ini = meio + 1;
	}

	if (caminho(dijkstra(fim + 1), fim + 1) != k)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for (auto[a, b] : arr)
		{
			b = (b ? b : fim + 1);
			cout << a.first << ' ' << a.second << ' ' << b << endl;
		}
	}
}
