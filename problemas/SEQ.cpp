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
#define MOD 1000000000
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

matrix b, t, r;
ll c[MAX], n, k, x;

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
		{
			r.m[i][j] = 0;
			for (int l = 0; l < k; l++)
				r.m[i][j] = (r.m[i][j] + ((a.m[i][l]*b.m[l][j]) % MOD)) % MOD;
			r.m[i][j] %= MOD;
		}

	return r;
}

matrix fexpo(matrix b, ll e)
{
	matrix r;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
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
	cin >> x;
	while (x--)
	{
		cin >> k;
		for (int i = k-1; i >= 0; i--)
			cin >> t.m[i][0];
		for (int i = 0; i < k; i++)
			cin >> b.m[0][i];

		for (int i = 1; i < k; i++)
			for (int j = 0; j < k; j++)
				b.m[i][j] = (i==j+1);	
		
		cin >> n;	
		if (n <= k) 
		{
			cout << t.m[n-1][0] << endl;
			continue;
		}

		r = fexpo(b, n-k);
		r = mult(r, t);
		cout << r.m[0][0] << endl;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				r.m[i][j] = b.m[i][j] = t.m[i][j] = 0;
	}
}














