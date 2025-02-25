#include <iostream>
#include <vector> 
#include <queue> 
#include <map> 
#define MAXN (int) (2e5 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, d, a, b, c, vis[MAXN];
vector<ii> grafo[MAXN];
vector<int> resp;

int pode(int maior)
{
	queue<ii> fila;
	map<int, int> vis;
	fila.push({1, 0});
	vis[1] = 1;

	while (!fila.empty())
	{
		auto[u, q] = fila.front(); fila.pop();
		if (q > d) continue;
		if (u == n) return 1;
		for (auto[v, w] : grafo[u])
		{
			if (w > maior) continue;
			if (vis.find(v) != vis.end()) continue;
			vis[v] = 1;
			fila.push({v, q+1});
		}
	}
	return 0;
}

int dfs(int u, int p = 0, int dist = 0, int maior = 0)
{
	if (dist > d) return 0;
	if (u == n)
	{
		cout << resp.size() << endl;
		cout << 1 << ' ';
		for (int x : resp) cout << x << ' ';
		cout << endl;
		return 1;
	}

	for (auto[v, w] : grafo[u])
	{
		if (v == p || w > maior || vis[v]) continue;
		resp.push_back(v);
		if (dfs(v, u, dist+1, maior)) return 1;
		resp.pop_back();
	}
	
	return 0;
}

int32_t main()
{
	cin >> n >> m >> d;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	int ini = 0, meio, fim = 1e9;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (pode(meio)) fim = meio - 1;
		else ini = meio + 1;
	}

	if (!dfs(1, 0, 0, fim + 1)) cout << -1 << endl;
}
