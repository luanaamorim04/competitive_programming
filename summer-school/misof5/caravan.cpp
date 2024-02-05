#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define INF (1e9)
#define MOD (int) (1e9 + 7)
#define all(x) x.begin(), x.end()
#define _ ios_base::sync_with_stdio(false); cin->tie(0);

using namespace std;

int dp[MAXN][26][26], t;
string s;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		for (int i = 1; i <= s.size(); i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				for (int q = 1; q <= 26; q++)
				{
					dp[i][c][q] += dp[i-1][]
				}
			}
		}
	}
	return 0;
}
