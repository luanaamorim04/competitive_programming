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
#define MAX (int) 5
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
	ll m[MAX][MAX];
};

ll f(ll x)
{
	return ((50-x)*(50-x)) / 100;
}

matrix mult(matrix a, matrix b)
{
	matrix r;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			r.m[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				r.m[i][j] = (r.m[i][j] + (a.m[i][k]*b.m[k][j]) % MOD) % MOD;
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
		e >>= 1;
	}

	return r;
}

ll n, resp;

int main()
{_
	cin >> n;
	matrix pietra = {{{f(10), f(20), f(30), f(40), 0},
					{1, 0, 0, 0, 0},
					{0, 1, 0, 0, 0},
					{0, 0, 1, 0, 0},
					{0, 0, 0, 1, 0}}};

	matrix pedro = {{{1, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0}}};

	matrix luca = mult(fexpo(pietra, n/10), pedro);
	for (int i = 0; i < (n%10 >= 5 ? 4 : 5); i++)
		resp = (resp + luca.m[i][0]) % MOD;

	cout << resp << endl; 
}












