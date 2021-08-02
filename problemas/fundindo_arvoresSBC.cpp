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
#define INF (1e9)
#define MAX (int) (2e5 + 5)
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

int n, m, g1[MAX][2], x, g2[MAX][2], r, r1;

int dfs(int u, int c)
{
	if (u == 0) return 0;
	int ans = max(dfs(g1[u][0], 0), dfs(g1[u][1], 1) + 1);
	r = max(r, ans);
	return (c ? ans : 0);
}

int dfs1(int u, int c)
{
	if (u == 0) return 0;
	int ans = max(dfs1(g2[u][0], 0), dfs1(g2[u][1], 1) + 1);
	r1 = max(r1, ans);
	return (c ? ans : 0);
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cin >> x;
		cin >> g1[x][0] >> g1[x][1];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{	
		cin >> x;
		cin >> g2[x][1] >> g2[x][0];
	}

	int c1 = dfs(1, 1);
	int c2 = dfs1(1, 1);

	cout << n+m - max(min(c2, r), min(c1, r1)) << endl;
}














