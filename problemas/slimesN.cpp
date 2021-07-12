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
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, psa[MAX], memo[401][401];

ll f(int i, int j)
{
	if (i == j) return 0;
	if (~memo[i][j]) return memo[i][j];
	ll ans = 1e14;
	for (int x = i; x < j; x++) ans = min(ans, f(i, x) + f(x+1, j));
	return memo[i][j] = ans + psa[j]-psa[i-1];
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> psa[i];
		psa[i] += psa[i-1];
	}

	memset(memo, -1, sizeof memo);
	cout << f(1, n) << endl;
}
