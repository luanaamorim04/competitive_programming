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

	for (int soma = 0; soma < MAXS; soma++)
		dp[soma][0] = 1e9 + 10;

	dp[0][0] = 0;
	for (int soma = 0; soma < MAXS; soma++)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[soma][i] = dp[soma][i-1];
			if (soma >= val[i]) 
			{
				dp[soma][i] = min(dp[soma][i], dp[soma-val[i]][i-1] + peso[i]);
//				printf("dp[%d][%d] = %d\n", soma, i, dp[soma][i]);
			}
		}
	}

	int resp = 0;
	for (int i = 0; i < MAXS; i++)
		if (dp[i][n] <= s) resp = i;

	cout << resp << endl;
	return 0;
}

