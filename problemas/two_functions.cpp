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
#define INF (1e9)
#define MAXN 6
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

struct matrix
{
	ll m[MAXN][MAXN];
};

ll t, a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, n, mod, q;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAXN; k++)
				r.m[i][j] = (r.m[i][j] + ((a.m[i][k]*b.m[k][j])%mod)) % mod;
		}
	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
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
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a1 >> b1 >> c1;
		cin >> a2 >> b2 >> c2;
		cin >> f0 >> f1 >> f2;
		cin >> g0 >> g1 >> g2;
		cin >> mod >> q;
		f0 %= mod, f1 %= mod, f2 %= mod, g0 %= mod, g1 %= mod, g2 %= mod;
		a1 %= mod, b1 %= mod, c1 %= mod, a2 %= mod, b2 %= mod, c2 %= mod;

		matrix base, pedro, resp;
		base = {{{a1, b1, 0LL, 0LL, 0LL, c1}, 
				{1LL, 0LL, 0LL, 0LL, 0LL, 0LL}, 
				{0LL, 1LL, 0LL, 0LL, 0LL, 0LL}, 
				{0LL, 0LL, c2, a2, b2, 0LL}, 
				{0LL, 0LL, 0LL, 1LL, 0LL, 0LL},
				{0LL, 0LL, 0LL, 0LL, 1LL, 0LL}}};

		pedro = {{{f2, 0LL, 0LL, 0LL, 0LL, 0LL}, 
				{f1, 0LL, 0LL, 0LL, 0LL, 0LL}, 
				{f0, 0LL, 0LL, 0LL, 0LL, 0LL}, 
				{g2, 0LL, 0LL, 0LL, 0LL, 0LL}, 
				{g1, 0LL, 0LL, 0LL, 0LL, 0LL},
				{g0, 0LL, 0LL, 0LL, 0LL, 0LL}}};

		cout << "Case " << i << ": \n";
		while (q--)
		{
			cin >> n;
			if (n < 3) 
			{
				if (n==0) cout << f0 << ' ' << g0 << endl;
				if (n==1) cout << f1 << ' ' << g1 << endl;
				if (n==2) cout << f2 << ' ' << g2 << endl;
				continue;
 			}
			resp = mult(fexpo(base, n-2), pedro);
			cout << resp.m[0][0] << ' ' << resp.m[3][0] << endl;
		}
	}
}	









