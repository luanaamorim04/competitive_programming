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
#define MAX (int) (2e6 + 5)
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

int n;
ll dp[MAX];

int main()
{_
	cin >> n;
	dp[1] = 2, dp[0] = 1;
	for (ll i = 2; i <= n; i++)
	{
		ll k = (i*(i-1)*4)%MOD;
		dp[i] = (((dp[i-1]*i*2)%MOD) + (dp[i-2]*k)) % MOD;
	}
	cout << dp[n] << endl;
}




















