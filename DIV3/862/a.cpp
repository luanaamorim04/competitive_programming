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
#define MAX (int) (2)
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
#define int long long

using namespace std;

struct Matrix
{
	int m[MAXN][MAXN];
};

Matrix mult(Matrix a, Matrix b)
{
	Matrix r;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAXN; k++)
				r.m[i][j] += (a.m[i][k]*b.m[k][j]);
		}

	return r;
}

Matrix fexpo(Matrix b, int e)
{
	Matrix r;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			r.m[i][j] = (i==j);

	while (e)
	{
		if (e&1) r = mult(r, b);
		b = mult(b, b);
		e >>= 1;
	}

	return r;
}

int n;

int32_t main()
{_
	cin >> n;
	Matrix base = {{1, 1}, {1, 0}};
	Matrix resp = fexpo(base, n);
	cout << resp.m[0][0] << endl;
}







