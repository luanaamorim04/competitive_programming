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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (1e6 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, a, b;

int main()
{_
	cin >> n >> m >> k;
	int dp[m+2][n+2], vis[m+2][n+2];
	memset(dp, 0, sizeof dp);
	memset(vis, 0, sizeof vis);

	for (int i = 1; i <= k; i++)
	{
		cin >> a >> b;
		vis[a][b] = 1;
	}
	
	dp[0][1] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (vis[i][j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

	cout << dp[m][n] << endl;
}










