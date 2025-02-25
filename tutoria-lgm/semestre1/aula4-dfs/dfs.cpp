#include <iostream>
#include <vector> 
#define MAXN (int) (1e5 + 10)

using namespace std;

vector<int> grafo[MAXN];
int a, b, n, m, vis[MAXN];

void dfs(int u, int p = 0)
{
	vis[u] = 1;
	cout << u << endl;
	for (int v : grafo[u])
	{
		//if (v == p) continue;
		if (!vis[v]) dfs(v, u);
	}

	vis[u] = 2;
}

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
		if (!vis[i]) dfs(i);
}
