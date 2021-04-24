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

ll n, k, a, b, arr[1<<20], dig[60], memo[60][2][60];

void dcomp(ll x)
{
	for (int i = n-1; i >= 0; i--)
	{
		if (arr[i] <= x) x -= arr[i], dig[i] = 1;
		else dig[i] = 0;
	}
}

ll f(int idx, int igual, int qnt)
{
	if (idx == -1) return qnt == k;
	ll &ans = memo[idx][igual][qnt];
	if (~ans) return ans;
	ans = 0;
	int l = igual ? dig[idx] : 1;

	for (int i = 0; i <= l; i++)
		ans += f(idx - 1, (igual & (i==l)), qnt + i);

	return ans;
}

ll solve(ll x)
{
	memset(memo, -1, sizeof memo);
	dcomp(x);
	return f(n-1, 1, 0);
}

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> a >> b;
	sort(arr, arr+n);
	cout << solve(b) - solve(a-1) << endl;
}







