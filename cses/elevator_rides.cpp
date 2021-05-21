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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, arr[20], m;
par dp[1<<20]; 

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i < (1<<n); i++)
	{
		dp[i] = {n+1, 0};
		for (int p = 0; p < n; p++)
		{
			if ((1<<p)&i)
			{
				par tmp = dp[i^(1<<p)];
				if (tmp.second + arr[p] <= m) tmp.second += arr[p];
				else tmp.first++, tmp.second = min(tmp.second, arr[p]);
				dp[i] = min(dp[i], tmp);
			}
		}
	}

	cout << dp[(1<<n) - 1].first + 1 << endl;
}














