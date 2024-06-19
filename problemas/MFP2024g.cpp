#include <bits/stdc++.h>
//#include <iostream>
#include <vector> 
#include <queue> 
#define MAXN (int) (3e3 + 10)
#define INF (int) (1e9)
#define ii pair<int, int> 
#define MOD (int) (1e9 + 7)

using namespace std;

int n, m, dp[MAXN][MAXN], arr[MAXN], resp, soma;

int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> arr[0];
	for (int i = 1; i < n; i++) 
	{
		cin >> arr[i];
	}
	sort(arr+1, arr+n);
	soma = arr[0];
	for (int i = 1; i < n; i++) if (arr[i] <= soma) soma += arr[i];

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++)
	{

		for (int j = arr[i]; j < m; j++)
		{
			dp[i][j+arr[i]] = (dp[i][j+arr[i]] + dp[i-1][j]) % MOD;
			if (j+arr[i] >= m) resp = (resp + dp[i][j+arr[i]]) % MOD;
		}
		for (int j = m; j >= 0; j--) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
	}

	if (soma < m) 
	{
		cout << 1 << endl;
		return 0;
	}
		
	cout << (arr[0] >= m ? (resp + 1) % MOD : resp) << endl;
}
