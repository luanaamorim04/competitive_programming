#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <bitset>
#define MAXN 20
#define MOD (int) (1e9 + 7)
#define int long long
#define ALL 660911389

using namespace std;

int n, m, a, b, dp[(1<<MAXN)][MAXN], grafo[MAXN][MAXN], last[MAXN], v[MAXN],q;

int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		grafo[a-1][b-1]++;
	}

	dp[1][0] = 1;
	for (int i = 1; i < (1<<n); i+= 2)
	{
		for (int u = 0; u < n; u++)
		{
			if (!(i&(1<<u))) continue;
			for (int v = 0; v < n; v++)
			{
				dp[i][v] = (dp[i][v] + grafo[u][v]*dp[i^(1<<v)][u]) % MOD;
			}
		}
	}

	cout << dp[(1<<n)-1][n-1] << endl;
}
