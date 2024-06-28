#include <iostream>
#include <vector>
#define MAXN (int) (2e3 + 10)

using namespace std;

int n, m, t, a, b, vis[MAXN], grau[MAXN], adj[MAXN][MAXN];
vector<int> grafo[MAXN], ciclo;

void dfs(int u, int p = 0)
{
	vis[u] = 1;
	ciclo.push_back(u);
	for (int v : grafo[u])
	{
		if (v == p) continue;
		if (vis[v] == 1) 
		{
			cout << "v: " << v << endl;
			int flag = -1, ok = 0;
			for (int i = 0; i < ciclo.size(); i++)
			{	
				int x = ciclo[i], soma = 0;
				if (x == v) flag = i;
				if (flag == -1) continue;
				for (int j = flag; j < ciclo.size(); j++) soma += adj[ciclo[i]][ciclo[j]];
				ok |= (grau[x] - soma  + 2== 4);
				printf("grau[%d] = %d\n", x, grau[x] - soma + 2);
			}	
			cout << ok << endl;

			flag = 0;
			if (ok)
			{
				for (int x : ciclo)
				{
					if (x == v) flag = 1;
					if (flag) cout << x << ' ';
				}
				cout << v << endl;
				return;
			}
		}
		else if (vis[v] == 2) continue;
		else dfs(v, u);
	}

	vis[u] = 2;
	ciclo.pop_back();
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		while (m--)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
			grau[a]++;
			adj[a][b] = adj[b][a] = 1;
			grau[b]++;
		}

		dfs(1);
		for (int i = 1; i <= n; i++) grafo[i].clear();
	}

}
