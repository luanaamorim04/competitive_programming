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
#define MAX (int) (2e5 + 5)
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

ll n, arr[MAX], x, dp[MAX][101], psa[MAX][101];

int main()
{_
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[0][n+1] = 1;
	for (int i = 0; i <= x; i++)
		psa[i][n+1] = 1;
	
	for (int i = n; i >= 1; i--)
		for (int j = 0; j <= x; j++)
		{
			dp[j][i] = (psa[j][i+1] - psa[max(0LL, j-arr[i])][i+1] + MOD + dp[max(0LL, j-arr[i])][i+1]) % MOD;
			psa[j][i] = (psa[max(0, j-1)][i] + dp[j][i]) % MOD;
		}

	cout << dp[x][1] << endl;
}












