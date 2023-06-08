// #include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAXN 303

using namespace std;

int n, arr[MAXN], a, idx, dp[MAXN][MAXN];

int32_t main()
{
	cin >> n;
	idx = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
		cin >> arr[i];
	}

	for (int l = n; l >= 1; l--)
	{
		for (int r = l+1; r <= n; r++)
		{
			if (arr[l] == arr[r])
			{
				dp[l][r] = dp[l+1][r-1] + 1;
				// 1 1 2 3 2 1
				for (int i = l+1; i < r; i++)
				{
					if (arr[i] == arr[l])
						dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] - 1);
				}
			}
			else
			{
				dp[l][r] = min(dp[l+1][r], dp[l][r-1]) + 1;
				for (int i = l+1; i < r; i++)
				{
					if (arr[i] == arr[l])
						dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
					if (arr[i] == arr[r])
						dp[l][r] = min(dp[l][r], dp[l][i-1] + dp[i][r]);
				}
			}


			// printf("dp[%d][%d] = %d\n", l, r, dp[l][r]);
		}
	}

	cout << dp[1][n] << endl;
}