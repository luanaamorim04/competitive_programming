#include <iostream> 
#define MAXS (int)(1e5 + 10)
#define int long long
#define MAXN 1004

using namespace std;

int n, s, peso[MAXN], dp[MAXS][MAXN], val[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> peso[i];
	for (int i = 1; i <= n; i++)
		cin >> val[i];

	for (int soma = s; soma >= 0; soma--)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[soma][i] = dp[soma][i-1];
			if (soma >= peso[i]) dp[soma][i] = max(dp[soma][i], dp[soma-peso[i]][i-1] + val[i]);
//			printf("dp[%d][%d] = %d\n", soma, i, dp[soma][i]);
		}
	}

	cout << dp[s][n] << endl;
	return 0;
}

