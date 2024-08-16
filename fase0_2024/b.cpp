#include <iostream>
#define MAXN (int) (5e3 + 10)
#define MOD 998244353

using namespace std;

int m, aberto, fechado, dp[MAXN][MAXN][2], n;
string s;

//int f(int idx, int qtd, int flag)
//{
//	if (qtd<0) return 0;
//	if (idx > n) return !qtd && flag;
//	int &ans = memo[idx][qtd][flag];
//	if (~ans) return ans;
//
//	ans = (f(idx+1, qtd-1, flag) + f(idx+1, qtd+1, flag)) % MOD;
//	if (!flag && qtd >= fechado) ans = (ans + f(idx+m, qtd-fechado+aberto, 1)) % MOD;
//
//	return ans;
//}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	m = s.size();
	for (char c : s)
	{		
		if (c == ')' && aberto) aberto--;
		else if (c == ')' && !aberto) fechado++;
		else if (c == '(') aberto++;	
	}

	dp[n+1][0][1] = 1;

	for (int idx = n; idx >= 1; idx--)
	{
		dp[idx][0][0] = dp[idx+1][1][0]; 
		dp[idx][0][1] = dp[idx+1][1][1]; 
		if (fechado <= 0 && idx+m <= n+1) dp[idx][0][0] = (dp[idx][0][0] + dp[idx+m][aberto][1]) % MOD;	
		for (int qtd = 1; qtd <= (n>>1); qtd++)
		{
			dp[idx][qtd][0] = (dp[idx+1][qtd-1][0] + dp[idx+1][qtd+1][0]) % MOD; 
			dp[idx][qtd][1] = (dp[idx+1][qtd-1][1] + dp[idx+1][qtd+1][1]) % MOD; 
			if (fechado <= qtd && idx+m <= n+1) dp[idx][qtd][0] = (dp[idx][qtd][0] + dp[idx+m][qtd-fechado+aberto][1]) % MOD;	
		}
	}

	cout << dp[1][0][0] << endl;
}
