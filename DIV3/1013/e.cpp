#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD 998244353
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n, m, d, dp[MAXN][MAXN][2], pula[MAXN][2], npula[MAXN][2];
char tab[MAXN][MAXN];

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> tab[i][j];	

		for (int i = 1; i <= m; i++)
		{
			npula[i][0] = pula[i][0] = m;
			npula[i][n] = pula[i][n] = 1;
			dp[n][i][0] = (tab[1][i] == 'X');
			for (int j = 1; j <= m; j++)
			{
				if (d*d < (i-j)*(i-j)) continue;
			   	npula[i][0] = min(npula[i][0], j);
				npula[i][1] = max(npula[i][1], j);
				if (d*d < 1 + (i-j)*(i-j)) continue;	
				pula[i][0] = min(pula[i][0], j);
				pula[i][1] = max(pula[i][1], j);
			}
			cout << pula[i][0] << ' ' << pula[i][1] << endl;
		}
		int resp = 0;
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j <= m; j++)
			{
				if (tab[i][j] == '#') continue;
				for (int k = pula[j][0]; k <= pula[j][1]; k++)
					dp[i][j][0] = (dp[i][j][0] + dp[i+1][k][1] + dp[i+1][k][0]);

				for (int k = npula[j][0]; k <= min(j-1, npula[j][1]); k++)
					dp[i][j][1] = (dp[i][j][1] + dp[i][k][0]);
				printf("dp[%d][%d][%d] = %d\n", i, j, 0, dp[i][j][0]);
				printf("dp[%d][%d][%d] = %d\n", i, j, 1, dp[i][j][1]);
			}
		}

		for (int i = 1; i <= m; i++)
			resp = (resp + dp[1][i][0] + dp[1][i][1]);
		cout << resp << endl;
	}
}
