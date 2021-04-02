#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 100
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct matrix
{
	ll m[MAX][MAX];
};

ll n, m, k, a, b;
matrix p;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] = (r.m[i][j] +  ((a.m[i][k]*b.m[k][j])% MOD)) % MOD;
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
		e>>= 1LL;
	}
	return r;
}

int main()
{_	
	cin >> n >> m >> k;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			p.m[i][j] = 0;

	while (m--)
	{
		cin >> a >> b;
		p.m[a - 1][b - 1]++;
	}

	cout << fexpo(p, k).m[0][n - 1] << endl;
}
