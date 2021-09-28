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
#define MAX 20
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

matrix t, b, r;
ll n, m, p, d, test, psa[MAX];

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] += (ll)((a.m[i][k]*b.m[k][j]) % p);
			r.m[i][j] %= p;
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

ll solve(ll n)
{
	if (n <= d) return psa[n-1];
	r = fexpo(b, n-d);
	r = mult(r, t);
	return r.m[d][0];
}

int main()
{_
	cin >> test;
	while (test--)
	{
		cin >> d;
		for (int i = d-1; i >= 0; i--)
			cin >> t.m[i][0]; 

		for (int i = 0; i < d; i++)
			cin >> b.m[0][i];

		b.m[d][d] = 1;
		for (int i = 1; i < d; i++)
			b.m[i][i-1] = 1;

		cin >> m >> n >> p;
		for (int i = 0; i < d; i++)
		{
			psa[i] = (psa[max(0, i-1)] + t.m[(d-i)-1][0]) % p;
			b.m[0][i] %= p;
			b.m[d][i] = b.m[0][i];
		}

		t.m[d][0] = psa[d-1];

		ll soma1 = solve(m-1);
		ll soma2 = solve(n);
		cout << (soma2-soma1+p)%p << endl;

		for (int i = 0; i <= d; i++)
			for (int j = 0; j <= d; j++)
				psa[i] = t.m[i][j] = b.m[i][j] = r.m[i][j] = 0;
	}
}












