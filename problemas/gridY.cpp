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
#define MAX (int) (1e6)
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

ll fat[MAX], n, m, q, c[MAX], l[MAX], a, b, idx, dp[MAX];
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
	int x = (c-a);
	int y = (d-b);
	return (fat[x+y] * fexpo((fat[x]*fat[y]) % MOD, MOD-2)) % MOD;
}

int main()
{_
	cin >> n >> m >> q;
	fat[0] = 1;
	for (int i = 1; i <= n+m; i++)
		fat[i] = (fat[i-1]*i) % MOD;

	while (q--)
	{
		cin >> a >> b;
		v.push_back({a, b});
	}

	v.push_back({n, m});
	sort(all(v));
	for (auto[a, b] : v)
		l[++idx] = a, c[idx] = b;

	for (int i = 1; i <= idx; i++)
		dp[i] = f(1, 1, l[i], c[i]);

	for (int i = 1; i <= idx; i++)
		for (int j = 1; j < i; j++)
		{
			if (c[j] > c[i]) continue;
			dp[i] = (dp[i] - (dp[j] * f(l[j], c[j], l[i], c[i]) % MOD) + MOD) % MOD;
		}

	cout << dp[idx] << endl;
}











