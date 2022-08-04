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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e15)
#define MAXN (int) (1e5 + 5)
#define MAX (int) (5e3 + 2)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define meio(x, y) ((x+y)>>1)
 
using namespace std;
 
int n, k, arr[MAX], t, inv[MAX][MAX];
ll dp[2][MAX], psa[MAX][MAX], c;
 
void divide(int i, int j, int l, int r)
{
	if (i > j || l == -1 || r == -1) return;
	int optmid = -1, m = meio(i, j);
	ll cur = INF, tot = psa[m][m];
	for (int k = l; k <= min(r, m); k++)
	{
		if (cur > dp[(t&1)^1][k-1] + (tot - psa[m][k-1])) 
			cur = dp[(t&1)^1][k-1] + (tot - psa[m][k-1]), optmid = k;
	}
	
	dp[t&1][m] = cur;
	divide(i, m-1, l, optmid);
	divide(m+1, j, optmid, r);
}
 
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
 
	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = INF;
		for (int j = i; j <= n; j++)
		{
			inv[i][j] = inv[i][j-1] + (arr[i]>arr[j]);
			psa[j][i] = psa[j][i-1] + inv[i][j];
		}
	}
 
	for (t = 1; t <= k; t++)
		divide(1, n, 1, n);
	cout << dp[k&1][n] << endl;
}  