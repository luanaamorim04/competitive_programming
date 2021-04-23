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
#define ll unsigned long long
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

ll n, memo[24][2][11], dig[24], resp, k;

int dcomp(ll x)
{	
	int idx = 0;
	while (x)
	{
		dig[idx++] = x%10;
		x/=10;
	}
	return idx-1;
}

ll f(int idx, int igual, int last)
{
	if (idx == -1) return 1;
	ll &ans = memo[idx][igual][last];
	if (ans) return ans;
	int l = (igual ? dig[idx] : 9), ok;

	for (int i = 0; i <= l; i++)
	{
		if ((i==4) || ((last==1) && (i==3))) continue;
		ans += f(idx - 1, (igual && (i==l)), i);
	}

	return ans;
}

ll solve(ll x)
{
	memset(memo, 0, sizeof(memo));
	int maxn = dcomp(x);
	return f(maxn, 1, -1) - 1;
}

int main()
{_
	while (cin >> n)
	{
		ll ini = 0, meio, fim = -1LL;
		while (ini <= fim)
		{
			meio = ini + ((fim-ini)>>1LL);
			if (solve(meio) >= n) fim = meio - 1;
			else ini = meio + 1;
		}

		cout << fim + 1 << endl;
	}
	return 0;
}














