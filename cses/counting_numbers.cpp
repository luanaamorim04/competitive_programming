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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll a, b, dig[20], memo[20][2][10][2];

int dcomp(ll x)
{
	int idx = 0;
	while (x)
	{
		dig[idx++] = x%10;
		x /= 10;
	}

	return idx-1;
}

ll f(int idx, int igual, int last, int null)
{
	if (idx == -1) return 1;
	ll &ans = memo[idx][igual][last][null];
	if (~ans) return ans;
	ans = 0;
	int l = igual ? dig[idx] : 9;

	for (int i = 0; i <= l; i++)
	{
		if (i != last || null) 
			ans += f(idx - 1, (igual & (i==l)), i, (null && !i));
	}

	return ans;
}

ll solve(ll x)
{
	memset(memo, -1, sizeof(memo));
	int maxn = dcomp(x);
	return f(maxn, 1, -1, 1);
}

int main()
{_
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << endl;
}












