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
#define ll long long
#define INF (1e9)
#define MAX 12
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct matrix
{
	ll m[MAX][MAX];
};

matrix t, p, r;
ll n, resp, idx;
int cores[12], c;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] = (r.m[i][j] + ((a.m[i][k]*b.m[k][j]) % MOD)) % MOD;
		}
	return r;
}

matrix fexpo(matrix a, ll e)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			r.m[i][j] = (i==j);

	while (e)
	{
		if (e&1LL) r = mult(r, a);  
		a = mult(a, a);
		e>>=1LL;
	}
	return r;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		c |= (1<<i);
		for (int j = 0; j < 3; j++)
		{
			if (j == i) continue;
			c<<=3, c |= (1<<j);
			for (int k = 0; k < 3; k++)
			{
				if (k == j) continue;
				c<<=3, c |= (1<<k);
				cores[idx++] = c;
				c>>=3;
			}
			c>>=3;
		}
		c>>=3;
	}

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			t.m[i][j] = !(cores[i] & cores[j]);

	for (int i = 0; i < 12; i++)
		p.m[i][0] = 1;

	t = fexpo(t, n-1);
	r = mult(t, p);

	for (int i = 0; i < MAX; i++)
		resp = (resp + r.m[i][0]) % MOD;

	cout << resp << endl;
}




