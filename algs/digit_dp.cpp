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

// quantos numeros de a-b q tem d

ll memo[2][2][20], a, b, d, n, dig[20];	

int decomp(ll x)
{
	int idx = 0;
	while (x)
	{
		dig[idx++] = x%10;
		x/=10;
	}
	return idx;
}

ll solve(int igual, int tem, int idx)
{
	if (idx == -1) return tem;

	ll &ans = memo[igual][tem][idx];

	if (~ans) return ans;

	int l = igual ? dig[idx] : 9;

	ans = 0;
	for (int i = 0; i <= l; i++)
	{
		ans += solve((igual & (i==l)), (tem | (i == d)), idx - 1);
	}

	return ans;
}

ll f(ll x)
{	
	n = decomp(x);
	memset(memo, -1, sizeof(memo));
	return solve(1, 0, n-1);
}

int main()
{_
	cin >> a >> b >> d;
	cout << f(b) - f(a-1) << endl;
}


