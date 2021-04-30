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
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll a, b, c, n;

ll fexpo(ll b, ll e, ll m)
{
	ll ans = 1;
	while (e)
	{
		if (e&1) ans = (ans * b) % m;
		b = (b * b) % m;
		e>>=1;
	}
	return ans;
}

int main()
{_
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		ll x = fexpo(b, c, MOD-1);
		cout << fexpo(a, x, MOD) << endl;
	}
}
