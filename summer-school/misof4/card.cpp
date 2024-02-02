#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#define MAXN 110
#define MOD (int) (1e9 + 7)
#define par tuple<int, int, int>
#define int long long
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
#define all(x) x.begin(), x.end()

using namespace std;

int dp[1001][MAXN], last[1001][MAXN], arr[MAXN], fat[MAXN], qtd[MAXN], n, resp;

int32_t main()
{
	cin >> n;
	fat[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		int num = arr[i];
		while (num)
		{
			num /= 10;
			qtd[i]++;
		}
		fat[i] = (fat[i-1]*i) % MOD;
	}

	dp[0][0] = 1;
	int base = 1;
	for (int dig = 0; dig <= 1000; dig++)
	{
		for (int q = 1; q <= n; q++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (dig >= qtd[i])
					dp[dig][q] = (dp[dig][q] + dp[dig-qtd[i]][q]*(base*arr[i]*fat[q]));

			}

			resp = (resp + dp[dig][q]) % MOD;

		}

		base = (base * 10) % MOD;
	}
	
	cout << resp << endl;
}
