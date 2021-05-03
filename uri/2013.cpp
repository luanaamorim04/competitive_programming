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

ll memo[20][2][2][11][11][11], n, dig[20], freq[20], k;

int dcomp(ll n)
{
	int idx = 0;
	while (n)
	{
		dig[idx++] = n%10;
		n/=10;
	}

	return idx;
}

ll f(int idx, int null, int igual, int q0, int q1, int q2)
{
	if (q0 < 0 || q1 < 0 || q2 < 0 || (null && idx == -1)) return 0;
	if (idx == -1) return 1;

	ll &ans = memo[idx][null][igual][q0][q1][q2];
	if (~ans) return ans;
	ans = 0;

	int l = igual ? dig[idx] : 9; 

	if (null) ans = f(idx-1, 1, 0, 10, 0, 0);

	for (int i = null; i <= l; i++)
	{
		freq[i]++;
		if (freq[i]==1) ans += f(idx-1, 0, (igual && i==l) ? 1 : 0, q0-1, q1+1, q2);
		if (freq[i]==2) ans += f(idx-1, 0, (igual && i==l) ? 1 : 0, q0, q1-1, q2+1);
		freq[i]--;
	}

	return ans;
}	

ll solve(ll n)
{	
	int maxn = dcomp(n);
	memset(memo, -1, sizeof(memo));
	return f(maxn-1, 1, 1, 10, 0, 0);
}

int main()
{_
	cin >> n;
	k = solve(n);

	unsigned long long ini = 1, meio, fim = 1e18;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (solve(meio) >= k) fim = meio - 1;
		else ini = meio + 1;
	}

	cout << fim + 1 << endl;
}









