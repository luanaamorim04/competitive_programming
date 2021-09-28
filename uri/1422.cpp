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
#define INF 13371337
#define MAX 4
#define MOD 13371337
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

matrix t, base;
ll n, a, b, c, d;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] += (a.m[i][k]*b.m[k][j]) % MOD;
			r.m[i][j]%=MOD;
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
		if (e&1) r = mult(r, b);
		b = mult(b, b);
		e>>=1;
	}

	return r;
}

int main()
{_
	while (cin >> n && n)
	{
		cin >> a >> b >> c >> d;
		t = {{{d, 0, 0, 0}, {c, 0, 0, 0}, {b, 0, 0, 0}, {a, 0, 0, 0}}};
		base = {{{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
		base = fexpo(base, n-3);
		t = mult(base, t);
		cout << t.m[0][0] << endl;
	}
}


















