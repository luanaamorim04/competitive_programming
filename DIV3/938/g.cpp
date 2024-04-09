#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <vector>
#define MAXN 102

using namespace std;

int t, freq[MAXN*MAXN*MAXN], tab[MAXN][MAXN], n, m;
vector<int> dp[MAXN][MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < MAXN; i++)
		dp[i][0].push_back(1), dp[0][i].push_back(1);
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j].clear();
				cin >> tab[i][j];
			}
		}
	
		dp[1][1].push_back(tab[1][1]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int k : dp[i-1][j])
				{
					int x = gcd(tab[i][j], k);
					if (!freq[x]) dp[i][j].push_back(x);
					freq[x] = 1;
				}

				for (int k : dp[i][j-1])
				{
					int x = gcd(tab[i][j], k);
					if (!freq[x]) dp[i][j].push_back(x);
					freq[x] = 1;
				}
				for (int k : dp[i-1][j])
					freq[(gcd(tab[i][j], k))] = 0;
				for (int k : dp[i][j-1])
					freq[(gcd(tab[i][j], k))] = 0;
			}
		}

		int resp = 0;
		for (int x : dp[n][m])
			resp = max(resp, x);
		cout << resp << endl;
	}
}
