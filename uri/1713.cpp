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
#define MAX 100
#define MOD (int) (1e4)
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

ll n, m, s, d, a, b, c, e;
matrix t;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j]) % MOD);
			r.m[i][j] %= MOD;
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

int main()
{_
	while (cin >> n >> m)
	{
		memset(t.m, 0, sizeof t.m);
		cin >> s >> d;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> a;
				t.m[i][a]++;
			}
		}

		t = fexpo(t, m);
		cout << t.m[s][d] << endl;
	}
}		












