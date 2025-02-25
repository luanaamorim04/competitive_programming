#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) 998244353 

using namespace std;

int t, n, fexpo[MAXN], arr[MAXN], psa[MAXN], dp[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	fexpo[0] = 1;
	for (int i = 1; i < MAXN; i++) fexpo[i] = (fexpo[i-1] * 2) % MOD;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		psa[n+1] = 0;
		for (int i = n; i >= 1; i--)
			psa[i] = psa[i+1] + (arr[i] == 2);
		psa[0] = psa[1];

		int resp = 0, last = 0, l = 0, menos = 0;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] == 3)
			{
				dp[i] = dp[last]*(fexpo[psa[last]-psa[i]]) % MOD; 
				while (l < i && psa[l]-psa[i])
				{
					if (arr[l] == 1) 
					{
						menos++;
						dp[i] = (dp[i] + fexpo[psa[l]-psa[i]]) % MOD;
					}
					l++;
				}

		//		printf("dp[%d] = %d\n", i, dp[i]-menos);
				resp = (resp + dp[i] - menos) % MOD;
				last = i;
			}	
		}

		cout << resp << endl;

	}
}
