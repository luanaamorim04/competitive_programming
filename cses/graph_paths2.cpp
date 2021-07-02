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
#define ll unsigned long long
#define INF (1ULL<<62)
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

struct matrix
{
	ll m[101][101];
};

ll n, m, k, a, b, c;
matrix base;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			r.m[i][j] = INF;
			for (int k = 1; k <= n; k++)
				r.m[i][j] = min(r.m[i][j], a.m[i][k] + b.m[k][j]);
		}

	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			r.m[i][j] = b.m[i][j];

	while (e)
	{
		if (e&1) r = mult(r, b);
		b = mult(b, b);
		e>>=1;
	}

	return r;
}

int main()
{_
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			base.m[i][j] = INF;

	while (m--)
	{
		cin >> a >> b >> c;
		base.m[a][b] = min(base.m[a][b], c);
	}

	matrix r = fexpo(base, k-1);
	if (r.m[1][n] == INF) cout << -1 << endl;
	else cout << r.m[1][n]<< endl;
}









