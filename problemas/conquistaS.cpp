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
#define ll long long
#define INF (1e6)
#define MAX (int) (3e3 + 1)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int tab[MAX][MAX], n, m, dp[5][MAX][MAX], vis[MAX][MAX];

int e(int a, int b)
{
	return (a>=0 && b>=0 && a<n && b<m && !vis[a][b]);
}

int f(int d, int a, int b)
{
	if (a == n-1 && b == m-1) return 0;
	if (~dp[d][a][b]) return dp[d][a][b];
	int ans = -INF;

	vis[a][b] = 1;
	if (e(a+1, b)) ans = max(ans, f(3, a+1, b) + tab[a+1][b]);
	if (e(a, b+1)) ans = max(ans, f(1, a, b+1) + tab[a][b+1]);
	if (e(a, b-1)) ans = max(ans, f(2, a, b-1) + tab[a][b-1]);
	vis[a][b] = 0;

	return dp[d][a][b] = ans;
}

int main()
{_
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> tab[i][j];

	cout << f(0, 0, 0) + tab[0][0] << endl;
}

