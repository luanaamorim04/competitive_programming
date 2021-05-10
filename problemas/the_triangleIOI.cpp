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

ll n, arr[101][101], memo[101][101];

ll f(int idx, int level)
{
	if (idx < 1 || idx > level) return -INF;
	if (level > n) return 0LL;
	if (~memo[idx][level]) return memo[idx][level];
	return memo[idx][level] = max(f(idx, level+1) + arr[idx][level+1], f(idx+1, level+1) + arr[idx+1][level+1]);
}

int main()
{_
	cin >> n;
	memset(memo, -1LL, sizeof(memo));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> arr[j][i];
		
	cout << f(1, 1) + arr[1][1] << endl;
}

















