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
#define MAX 10
#define MOD (int) (1e6)
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

matrix r, b, t;
ll n, k, l;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] += ((a.m[i][k]*b.m[k][j])%MOD);
			
			r.m[i][j] %=MOD;
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
	while (cin >> n >> k >> l)
	{
		k %= MOD;
		l %= MOD;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				r.m[i][j] = t.m[i][j] = b.m[i][j] = 0;

		t.m[9][0] = 1;
		t.m[4][0] = k;
		b.m[0][4] = k;
		b.m[0][9] = l;
		for (int i = 1; i < MAX; i++)
			b.m[i][i-1] = 1;

		if (n < 10)
		{
			string resp = to_string(n==5?k:0);
			int tam = sz(resp);
			while (tam < 6)
			{
				tam++;
				cout << '0';
			}
			cout << resp << endl;
			continue;
		}
		r = fexpo(b, n-9);
		r = mult(r, t);
		string resp = to_string(r.m[0][0]);
		int tam = sz(resp);
		while (tam < 6)
		{
			tam++;
			cout << '0';
		}
		cout << resp << endl;
	}
}







