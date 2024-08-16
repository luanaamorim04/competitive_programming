#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define MAXN 105

int dp[1000][MAXN], q[MAXN], val[MAXN], base, n;

using namespace std;

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		int num = val[i];
		while (num)
		{
			num /= 10;
			q[i]++;
		}
	}

	for (int i = 1; i <= n; i++) //quantidade num
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			for (int soma = q[j]; soma <= 1000; soma++)
				dp[soma] = (dp[soma] + )
		}
	}
}


