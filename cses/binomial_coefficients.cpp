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
#define MAX (int) (2e6)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, a, b, fat[MAX];

ll fexpo(ll b, ll e)
{
	ll r = 1;
	while (e)
	{
		if (e&1) r = (r * b) % MOD;
		b = (b * b) % MOD;
		e>>=1;
	}
	return r;
}

ll resto(ll n, ll k)
{
	return (fat[n] * fexpo((fat[k]*fat[n-k]) % MOD, MOD-2)) % MOD;
}

int main()
{_
	cin >> n;
	fat[0] = 1;
	for (int i = 1; i < MAX; i++)
		fat[i] = (fat[i-1]*i) % MOD;

	while (n--)
	{
		cin >> a >> b;
		cout << resto(a, b) << endl;
	}
}








