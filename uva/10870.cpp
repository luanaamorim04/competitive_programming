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
#define MAX 15
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
	ll m[MAX][MAX];
};

ll d, n, m;
matrix r, b, t;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < d; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j])%m);
			r.m[i][j] %= m;
		}
	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
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
	while (cin >> d >> n >> m && m)
	{
		for (int i = 0; i < d; i++)
		{
			cin >> b.m[0][i];
			b.m[0][i] %= m;
		}
		for (int i = d-1; i >= 0; i--)
		{
			cin >> t.m[i][0];
			t.m[i][0] %= m;
		}

		for (int i = 1; i < d; i++)
			b.m[i][i-1] = 1;

		if (n <= d)
		{
			cout << t.m[n-1][0] << endl;
			continue;
		}

		r = fexpo(b, n-d);
		r = mult(r, t);
		cout << r.m[0][0] << endl;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				r.m[i][j] = b.m[i][j] = t.m[i][j] = 0;
	}
}
















