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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e18)
#define MAX (int) (405)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll psa[MAX], n, resp, memo[MAX][MAX], arr[MAX];
double m;

ll f(int l, int r)
{
	if (l == r) return 0;
	if (~memo[l][r]) return memo[l][r];
	ll ans = INF;
	for (int i = l; i < r; i++)
		ans = min(ans, f(l, i) + f(i+1, r) + max(psa[i]-psa[l-1], psa[r]-psa[i]));

	return memo[l][r] = ans;
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psa[i] = arr[i] + psa[i-1];
	}

	for (int i = n+1; i <= (n<<1); i++)
		psa[i] = psa[i-1] + arr[i-n];

	memset(memo, -1, sizeof memo);
	resp = INF;
	for (int i = 1; i <= n; i++)
		resp = min(resp, f(i, n+i-1));

	cout << fixed << setprecision(2) << (double)resp*m << endl;
}












