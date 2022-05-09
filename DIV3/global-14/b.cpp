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

ll t, n, ans;

ll bb(ll n)
{
	ll ini = 1, meio, fim = MAX;
	while (ini <= fim)
	{
		meio = (ini + ((fim-ini)/2));
		if (meio*meio <= n) ini = meio +1;
		else fim = meio - 1;
	}
	return ini - 1;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		ll k = bb(n>>1);
		ll l = bb(n>>2);
		ans |= (k*k == (n>>1) || (n%4==0 && (l*l == (n>>2))));
		cout << (ans && !(n&1) ? "YES" : "NO") << endl;
	}
}













