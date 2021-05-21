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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007LL
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, ans;

ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}

ll f(ll x)
{
	ll a = (n/(x+1)) % MOD, b = (n/x) % MOD;
	a = (a*(a+1)) % MOD;
	b = (b*(b+1)) % MOD;
	a = (a*inv(2, MOD)) % MOD;
	b = (b*inv(2, MOD)) % MOD;
	ll ans = (b - a + MOD) % MOD;
	return (ans*(x % MOD)) % MOD; 
}

int main()
{_
	cin >> n;
	ll x = n, idx = 1;
	while (idx)
	{
		ans = (ans + f(idx)) % MOD;
		x = n/(idx+1);
		if (!x) break;
		idx = n/x;
	}

	cout << ans << endl;
}











