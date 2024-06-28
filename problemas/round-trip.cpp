#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, m, vis[MAXN], a, b, pai[MAXN], ok;
vector<int> grafo[MAXN], resp;

int dfs(int u, int p = 0)
{
	vis[u] = 1, pai[u] = p;
	int r = 0;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		if (vis[v] == 1) 
		{
			int curr = u;
			resp.push_back(v);
			while (curr != v)
			{
				resp.push_back(curr);
				curr = pai[curr];
			}
			resp.push_back(v);
			cout << resp.size() << endl;
			for (int x : resp) cout << x << ' ';
			cout << endl;
			return 1;
		}
		if (!vis[v])
		{
			if (dfs(v, u)) return 1;
		}
	}
	vis[u] = 2;
	return r;
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

	for (int i = 1; i <= n; i++) if (!vis[i] && dfs(i)) return 0;

	cout << "IMPOSSIBLE" << endl;	
}
