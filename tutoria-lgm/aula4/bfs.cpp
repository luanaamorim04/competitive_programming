#include <iostream> 
#include <queue> 
#include <vector> 
#define MAXN (int) (1e5 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, a, b, vis[MAXN];
vector<int> grafo[MAXN];

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		queue<ii> fila;
		fila.push({i, 0});
		vis[i] = 1;
		while (!fila.empty())
		{
			auto[u, nivel] = fila.front(); fila.pop();
			cout << u << ": " << nivel << endl;
			for (int v : grafo[u])
			{
				if (vis[v]) continue;
				fila.push({v, nivel + 1});
				vis[v] = 1;
			}
		}
	}
}
