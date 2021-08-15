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

ll n, x, arr[105], dp[10005][105], resp, dp2[10005][105];

// ll f(int idx, int score, int qnt)
// {
// 	if (qnt < 0) return 0;
// 	if (idx == 0) return ((score <= x) && (!qnt));
	
// 	return memo[idx][score][qnt] = (f(idx - 1, score + arr[idx], qnt + 1)
// 	 + (f(idx - 1, score, qnt)*(qnt+1)) 
// 	 + (f(idx - 1, score - arr[idx], qnt - 1)*qnt));
// }

int main()
{_
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+1+n);
	
	for (int i = 0; i <= x; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 10000; j >= 0; j--)
			for (int k = 0; k <= (n-(i-1)); k++)
				dp2[j][k] = dp[j][k];

		for (int j = 10000; j >= 0; j--)
			for (int k = 0; k <= (n-i); k++)
			{
				dp[j][k] = (dp2[j+arr[i]][k+1] + ((dp2[j][k]*(k+1))%MOD))%MOD;
				if (j >= arr[i] && k) dp[j][k] = (dp[j][k] + ((dp2[j-arr[i]][k-1]*k)%MOD))%MOD;
			}
	}

	cout << dp[0][0] << endl;
}




