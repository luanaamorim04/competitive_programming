#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (1e6 + 5)
#define int long long

using namespace std;

int n, nxt[MAXN], dp[MAXN][2], vis[MAXN], dp2[MAXN][2], grau2[MAXN], resp, grau[MAXN], ciclo[MAXN];
vector<int> ord, grafo[MAXN];
queue<int> fila;

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nxt[i];
		grau[nxt[i]]++;
		grau2[nxt[i]]++;
		grafo[nxt[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (!grau[i]) fila.push(i);

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		ciclo[u] = 1;
		grau[nxt[u]]--;
		if (!grau[nxt[u]]) fila.push(nxt[u]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!ciclo[i] && !vis[i])
		{
			int x = nxt[i];
			grau2[x]--;
			nxt[i] = 0;

			// printf("grau[%d] = %d | grau[%d] = %d\n", i, grau2[i], x, grau2[x]);
		
			for (int j = 0; j <= n; j++)
				if (!grau2[j] && !vis[j]) fila.push(j), dp[j][0] = -1, dp2[j][0] = -1;

			while (!fila.empty())
			{
				int u = fila.front(); fila.pop();
				if (!u) continue;
				vis[u] = 1, grau2[nxt[u]]--;
				dp[i][0] = -1;
				for (int v : grafo[u])
				{
					if (v != i) dp2[u][1] += max(dp2[v][1], dp2[v][0] + 1);
					dp[u][1] += max(dp[v][1], dp[v][0] + 1);
				}

				for (int v : grafo[u])
				{
					dp[u][0] = max(dp[u][0], dp[u][1] - max(dp[v][1], dp[v][0] + 1) + dp[v][1]);
					if (v != i) dp2[u][0] = max(dp2[u][0], dp2[u][1] - max(dp2[v][1], dp2[v][0] + 1) + dp2[v][1]);
				}

				// printf("dp[%d][0] = %d | dp[%d][1] = %d\n", u, dp[u][0], u, dp[u][1]);
				if (!grau2[nxt[u]]) fila.push(nxt[u]);
			}

			resp += max(dp[i][1], max(dp2[i][0]+1, dp2[i][1]));
		}
	}

	cout << resp << endl;
	return 0;
}