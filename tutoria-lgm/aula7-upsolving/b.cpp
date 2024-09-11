#include <iostream>
#define MAXN (int) (1e5 + 10)

using namespace std;

int resp, n, k, dp[MAXN][3], dois[MAXN];
string s;

int32_t main()
{
	cin >> n >> k >> s;
	int curr = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '1') resp = (resp + curr) % 3;
		curr = (2*curr) % 3;
	}

	dois[0] = 1;
	for (int i = 1; i <= 2*k+n; i++)
		dois[i] = (2*dois[i-1]) % 3;

	dp[0][2*k] = 0;
	dp[1][2*k] = 1;
	dp[2][2*k] = 1;
	for (int i = 2*k-1; i >= 0; i--)
	{
		dp[1][i] = (!dp[2][i+1]) | (!dp[0][i+1]);
		dp[2][i] = (!dp[2][i+1]) | (!dp[1][i+1]) | (!dp[(dois[n+i]+2)%3][i+1]);
		dp[0][i] = (!dp[0][i+1]) | (!dp[1][i+1]) | (!dp[dois[n+i]][i+1]);

	}

	cout << (dp[resp][0] ? "GIOVANA" : "JULIA") << endl;
}
