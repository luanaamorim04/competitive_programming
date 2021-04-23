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

map<ll, int> val;
ll ft[1<<20], n, arr[1<<20], cp[1<<20];
ll ans;

ll query(int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans = (ans + ft[idx]) % MOD;
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, ll val)
{
	while (idx <= n)
	{
		ft[idx] = (ft[idx] + val) % MOD;
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cp[i] = arr[i];
	}

	sort(cp, cp+n);
	update(1, 1);

	for (int i = 0; i < n; i++)
		val[cp[i]] = i+1;

	for (int i = 0; i < n; i++)
	{
		ll k = query(val[arr[i]]); 
		update(val[arr[i]] + 1, k);
		ans = (ans + k) % MOD;
	}

	cout << ans << endl;
}












