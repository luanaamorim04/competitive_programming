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
#define MAX 5
#define MOD 1000000007
#define MMOD (MOD-1)
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
	ll m[MAX][MAX];
};

matrix b, t;
ll a1, a2, a3, n, x, resp;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j]) % MMOD);
			r.m[i][j] %= MMOD;
		}

	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			r.m[i][j] = (i==j);

	while (e)
	{
		if (e&1LL) r = mult(r, b);
		b = mult(b, b);
		e>>=1;
	}
	return r;
}

ll solve(matrix b, matrix t, ll n)
{
	matrix r;
	r = fexpo(b, n-3);
	r = mult(r, t);
	return r.m[0][0];
}

ll expo(ll b, ll e)
{
	ll r = 1;
	while (e)
	{
		if (e&1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e>>=1;
	}

	return r;
}

int main()
{_
	cin >> n >> a1 >> a2 >> a3 >> x;
	memset(b.m, 0, sizeof b.m);
	memset(t.m, 0, sizeof t.m);

	b.m[0][0] = b.m[0][1] = b.m[0][2] = 1;
	for (int i = 1; i < 3; i++)
		b.m[i][i-1] = 1;

	t.m[2][0] = 1;
	resp = expo(a1, solve(b, t, n)) % MOD;

	t.m[2][0] = 0;
	t.m[1][0] = 1;
	resp = (resp * expo(a2, solve(b, t, n))) % MOD;

	t.m[1][0] = 0;
	t.m[0][0] = 1;
	resp = (resp * expo(a3, solve(b, t, n))) % MOD; 

	t.m[0][0] = 0;
	t.m[3][0] = 4;
	t.m[4][0] = 1;

	memset(b.m, 0, sizeof b.m);
	for (int i = 0; i < 3; i++)
		b.m[0][i] = 1;

	b.m[0][4] = (-6+MMOD);
	b.m[0][3] = 2;
	b.m[1][0] = b.m[2][1] = b.m[3][3] = b.m[3][4] = b.m[4][4] = 1;
	resp = (resp * expo(x, solve(b, t, n))) % MOD; 

	cout << resp << endl;
}













