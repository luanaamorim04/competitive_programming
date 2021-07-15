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

ll memo[MAX][2], n, a, b;
vector<int> grafo[MAX];

ll f(int u, int p, int cor)
{
	ll &ans = memo[u][cor];
	if (~ans) return ans;
	ans = 1;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		if (cor == 1)
			ans = (ans * ((f(v, u, cor) + f(v, u, cor^1)) % MOD)) % MOD;
		else
			ans = (ans * f(v, u, cor^1)) % MOD;
	}

	return memo[u][cor] = ans;
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	memset(memo, -1, sizeof memo);
	cout << (f(1, 0, 0) + f(1, 0, 1)) % MOD << endl;
}















