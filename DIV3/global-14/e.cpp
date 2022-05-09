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

ll n, memo[500][500], m, on[500], resp;

ll f(int idx, int qnt)
{
	if (idx > n || idx < 1) return 0;
	ll &ans = memo[idx][qnt];
	if (~ans) return ans;
	ans = 0;

	on[idx] = 1, qnt++;
	int k1 = 0, k2 = 0;
	if (idx<n-1 && on[idx+2] && !on[idx+1]) on[idx+1] = 1, qnt++, k1 = 1;
	if (idx>2 && on[idx-2] && !on[idx-1]) on[idx-1] = 1, qnt++, k2 = 1;;

	if (qnt >= n) 
	{
		on[idx] = 0;
		if (idx<n-1 && on[idx+2] && k1) on[idx+1] = 0;
		if (idx>2 && on[idx-2] && k2) on[idx-1] = 0;
		return 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!on[i]) ans = (ans + f(i, qnt)) % m;
	}

	on[idx] = 0;
	if (idx<n-1 && on[idx+2] && k1) on[idx+1] = 0;
	if (idx>2 && on[idx-2] && k2) on[idx-1] = 0;
	
	return ans;
}	

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		memset(memo, -1, sizeof(memo));
		resp = (resp + f(i, 0)) % m;
	}
	cout << resp << endl;
}











