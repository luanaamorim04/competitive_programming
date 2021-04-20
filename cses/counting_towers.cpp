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
#define ll long long
#define INF (1e9)
#define MAX (1e6)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll dp[1<<20][2];
int n, t;

int main()
{_
	cin >> t;
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= MAX; i++)
	{
		dp[i][0] = (dp[i-1][1] + ((4*dp[i-1][0]) % MOD)) % MOD;
		dp[i][1] = (((2*dp[i-1][1]) % MOD) + dp[i-1][0]) % MOD;
	}

	while (t--)
	{
		cin >> n;
		cout << (dp[n-1][1] + dp[n-1][0]) % MOD << endl;
	}
}


















