#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAXN (int) (1e6 + 10)
#define MAXK (int) (5e3 + 10)
#define INF (int) (1e9)
#define int long long
#define MOD (int) (1e9 + 7)
#define max(a, b) (a>b?a:b)

using namespace std;

int n, last[MAXK][100], dp[MAXK][100];
string s;

int32_t main()
{
	cin >> n >> s;
	for (int i = 0; i <= s.size(); i++)
	{
		for (char c = 'A'; c <= 'Z'; c++)
			dp[i][c] = -INF;
	}

	if (s[0] == '.')
	{
		for (char c = 'A'; c < 'A' + n; c++)
			dp[1][c] = 0;
	}
	else
	{
		dp[1][s[0]] = 0;
	}

	for (int i = 2; i <= s.size(); i++)
	{
		if (s[i-1] != '.') 
		{
			for (char c = 'A'; c <= 'Z'; c++)
			{
				if (dp[i][s[i-1]] < dp[i-1][c] + (c != s[i-1]))
				{
					dp[i][s[i-1]] = max(dp[i][s[i-1]], dp[i-1][c] + (c != s[i-1]));
					last[i][s[i-1]] = c;
				}
			}
			continue;
		}

		for (char cur = 'A'; cur < 'A' + n; cur++)
		{
			for (char prev = 'A'; prev <= 'Z'; prev++)
			{
				
				if (dp[i][cur] < dp[i-1][prev] + (prev != cur))
				{
					dp[i][cur] = max(dp[i][cur], dp[i-1][prev] + (prev != cur));
					last[i][cur] = prev;
				}
			}
		}
	}

	int ans = 0;
	for (char c = 'A'; c <= 'Z'; c++)
		ans = max(ans, dp[s.size()][c]);

	vector<char> v;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		if (dp[s.size()][c] == ans)
		{
			int idx = s.size();
			char cur = c;
			while (idx)
			{
				v.push_back(cur);
				cur = last[idx][cur];
				idx--;
			}

			reverse(v.begin(), v.end());
			for (char k : v) cout << k;
			cout << endl;
			return 0;
		}
	}
}
