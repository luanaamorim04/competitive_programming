#include <iostream>
#include <vector>
#include <map>
//#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MAXN (int) (1e5 + 10)
#define ii pair<int, int> 

using namespace std;

int resp[1001], k, n, val[MAXN], pai[MAXN], folhas[MAXN];
vector<int> grafo[MAXN], dp[MAXN];

void f(int u, int p)
{
	for (int v : grafo[u])
	{
		f(v, u);
		folhas[u] += folhas[v];
	}

	folhas[u] = min(folhas[u], k);
	folhas[u] = max(folhas[u], 1LL);
	resize(dp[u].begin(), dp[u].end());
	if (folhas[u] == 1)
	{
		dp[u][1] = val[u];
		return;
	}

	for (int i = 1; i <= folhas[u]; i++)
		dp[u][i] = (i < fol])dp[grafo[u][0]][i];

	for (int idx = 1; idx < grafo[u].size(); idx++)
	{
		int curr = grafo[u][idx];
		for (int i = 1; i <= folhas[u]; i++)
		{
			resp[i] = dp[u][i];
			for (int j = 1; i+j <= folhas[u]; j++)
				dp[u][i+j] = max(dp[u][i+j], dp[curr][j] + resp[i]);
		}
	}
	folhas[u] = max(folhas[u], 1LL);
	dp[u][1] = max(dp[u][1], val[u]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) 
		cin >> val[i];
	for (int i = 2; i <= n; i++)
	{
		cin >> pai[i];
		grafo[pai[i]].push_back(i);
	}

	f(1, 0);
	cout << dp[1][k] << endl;
}






