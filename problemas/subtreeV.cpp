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
#define MAX (int) (2e5 + 5)
//#define MOD 1000000007
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

ll dp[MAX], n, a, b, resp[MAX], pai[MAX], rp[MAX], pos[MAX], MOD;
vector<int> grafo[MAX];
vector<ll> psa[MAX], ssa[MAX];
queue<par> fila;

ll f(int u, int p)
{
	pai[u] = p;
	if (~dp[u]) return dp[u];
	ll ans = 1;
	for (int v : grafo[u])
		if (v != p) ans = (ans * (f(v, u) + 1)) % MOD;

	return dp[u] = ans;
}
	
int main()
{_
	cin >> n >> MOD;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	memset(dp, -1, sizeof dp);	
	f(1, 0);

	for (int u = 1; u <= n; u++)
	{
		resp[u] = dp[u];
		psa[u].push_back(1);
		ssa[u].push_back(1);
		int idx = 1;
		for (int v : grafo[u])
		{
			if (v == pai[u]) continue;
			psa[u].push_back(dp[v] + 1);
			ssa[u].push_back(dp[v] + 1);
			pos[v] = idx++;
		}
		ssa[u].push_back(1);

		for (int j = 1; j < sz(psa[u]); j++)
			psa[u][j] = (psa[u][j-1] * psa[u][j]) % MOD;
		for (int j = sz(ssa[u]) - 2; j >= 0; j--)
			ssa[u][j] = (ssa[u][j+1] * ssa[u][j]) % MOD;
	}	

	fila.push({1, 0});
	rp[1] = 1;
	while (!fila.empty())
	{
		auto[u, p] = fila.front(); fila.pop();

		if (p)
		{
			ll x = (((rp[p] * psa[p][pos[u] - 1]) % MOD) * ssa[p][pos[u] + 1]) % MOD;
			rp[u] = (x + 1);
			resp[u] = (resp[u] * rp[u]) % MOD;
		} 
	
		for (int v : grafo[u])
			if (v != p) fila.push({v, u});
	}

	for (int i = 1; i <= n; i++)
		cout << resp[i] << endl;
}










