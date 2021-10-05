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
#define MAX (int) (2e6 + 5)
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

ll n, m, a, b, dp[MAX], fat[MAX];
vector<par> v;

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

ll f(int a, int b, int c, int d)
{
	c = abs(c-a);
	d = abs(d-b);
	return (fat[c+d] * fexpo((fat[c]*fat[d]) % MOD, MOD-2)) % MOD;
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		v.push_back({a, b});
	}

	fat[0] = 1;
	for (int i = 1; i <= 2*n; i++)
		fat[i] = (fat[i-1]*i) % MOD;

	v.push_back({n, n});
	sort(all(v));

	int idx = 0;
	for (int i = 0; i < sz(v); i++)
	{
		auto[a, b] = v[i];
		dp[i] = f(1, 1, a, b); 
		for (int j = 0; j < i; j++)
		{
			auto[c, d] = v[j];
			if (d > b) continue;
			dp[i] = (dp[i] - ((dp[j]*f(a, b, c, d)) % MOD) + MOD) % MOD;
		}
	}

	cout << dp[sz(v)-1] << endl;
}
















