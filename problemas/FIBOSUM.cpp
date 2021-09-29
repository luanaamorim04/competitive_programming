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

struct matrix{
	ll m[3][3];
};

ll n, m, t;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < 3; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j]) % MOD);
			r.m[i][j] %= MOD;
		}

	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.m[i][j] = (i==j);

	while (e)
	{
		if (e&1LL) r = mult(r, b);
		b = mult(b, b);
		e>>=1;
	}

	return r;
}

ll solve(ll n)
{
	if (n < 0) return 0;
	if (!n) return 1;
	matrix t = {{{1, 0, 0}, {0, 0, 0}, {1, 0, 0}}};
	matrix b = {{{1, 1, 0}, {1, 0, 0}, {1, 1, 1}}};
	b = fexpo(b, n);
	b = mult(b, t);

	return b.m[2][0];
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << (solve(m-1)-solve(n-2)+MOD) % MOD << endl;
	}
}
















