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
#define MAX (int) (1e6 + 5)
#define MOD 98765431
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
	ll m[2][2];
};

ll arr[MAX], n, m, soma;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < 2; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j]) % MOD);
			r.m[i][j] %= MOD;
		}

	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			r.m[i][j] = (i==j);

	while (e)
	{
		if (e&1LL) r = mult(r, b);
		b = mult(b, b);
		e>>=1LL;
	}

	return r;
}

ll solve(ll a, ll soma)
{
	matrix r = {{{(-1+MOD)%MOD, soma}, {0, n-1}}};
	matrix t = {{{a, 0}, {1, 0}}};
	r = fexpo(r, m);
	r = mult(r, t);

	return r.m[0][0];
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] %= MOD;
		soma = (soma + arr[i]) % MOD;
	}

	for (int i = 1; i <= n; i++)
		cout << solve(arr[i], soma) << endl;
}

















