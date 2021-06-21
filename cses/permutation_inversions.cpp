#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) 501
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dp[MAX][MAX*MAX], psa[MAX][MAX*MAX], n, k;

int main()
{_
	cin >> n >> k;

	dp[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= ((n-1)*n)>>1; j++)
		{
			int x = min(j+1, i) - 1;
			dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
			//dp[i][j] = (dp[i][j] + psa[i-1][j])
			dp[i][j] = (dp[i][j] + (((psa[i-1][j] - psa[i-1][j-x] + MOD) % MOD))) % MOD;
			psa[i][j] = ((j ? psa[i][j-1] : 0) + dp[i][j]) % MOD;
		}
	}
	cout << dp[n][k] << endl;
}





