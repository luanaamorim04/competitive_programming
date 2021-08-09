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
#define MAX (int) ((1<<20) + 5)
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

int n, m, k, x;
ll A[MAX], B[MAX], resp;

ll fexpo(int e)
{
	ll b = 2;
	ll resp = 1;
	while (e)
	{
		if (e&1) resp = (resp*b) % MOD;
		b = (b*b) % MOD;
		e>>=1;
	}	
	return (resp);
}

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		int mask = 0;
		while (k--)
		{
			cin >> x;
			mask |= (1<<(x-1));
		}

		A[mask]++;
	}

	for (int j = 0; j < m; j++) 
		for (int i = 0; i < (1<<m); i++) 
			if (i&(1<<j)) A[i] += A[i^(1<<j)];

	for (int i = 0; i < (1<<m); i++)
	{
		B[i] = fexpo(A[i]);
		if ((__builtin_popcount(i)&1)^(m&1)) resp = (resp - B[i] + MOD) % MOD;
		else resp = (resp + B[i]) % MOD;
	}

	cout << resp << endl;
}















