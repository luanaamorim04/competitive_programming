#include <iostream> 
#define MAXS (int)(1e5 + 10)
#define int long long
#define MAXN 201

using namespace std;

int n, s, peso[MAXN], dp[MAXS][MAXN], val[MAXN];

int32_t main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> peso[i] >> val[i];

	for (int soma = 0; soma <= s; soma++)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[soma][i] = dp[soma][i-1];
			if (soma >= peso[i]) dp[soma][i] = max(dp[soma][i], dp[soma-peso[i]][i-1] + val[i]);
		}
	}

	cout << dp[s][n] << endl;
	return 0;
}
