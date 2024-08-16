#include <iostream>
#define MAXN 110

using namespace std;

int n, val[MAXN], dig[MAXN], resp, dp[1000][MAXN];
bitset<MAXN> dp;

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		int num = val[i];
		while (num)
		{
			num/=10;
			dig[i]++;
		}
	}

	for (int j = 1; j <= n; j++)
	{
		for (int soma = dig[j]; soma <= 1000; soma++)
		{
			int base = 1, soma = 0;
			for (int qtd = 1; qtd <= n; qtd++) 
			{
				soma = (soma + base) % MOD;
				base = (base * 10) % MOD;
				dp[soma][qtd] = (dp[soma][qtd] + dp[soma-dig[j]][qtd-1]) % MOD;
			}
		}
	}
}
