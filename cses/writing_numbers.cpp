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

ll dig[20], n, memo[20][2][20][2], d;

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

ll f(int idx, int igual, int qnt, int null)
{
	if (idx == -1) return qnt;
	ll &ans = memo[idx][igual][qnt][null];
	if (~ans) return ans;
	int l = igual ? dig[idx] : 9;
	ans = 0;

	for (int i = 0; i <= l; i++)
		ans += f(idx - 1, (igual & (i==l)), qnt + (i==d && (!null || d)), (!null || d));

	return ans;
}

ll solve(ll x)
{
	ll ans = 0;
	int maxn = dcomp(x);
	d = 0;
	for (ll &i = d; i <= dig[maxn]; i++)
	{
		memset(memo, -1, sizeof(memo));
		ans = max(ans, f(maxn, 1, 0, 1));
	}
	return ans;
}


int main()
{_
	cin >> n;
	ll ini = 0, meio, fim = 1LL<<60;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1LL);
		if (solve(meio) <= n) ini = meio + 1;
		else fim = meio - 1;
	}

	cout << ini - 1 << endl;
}















