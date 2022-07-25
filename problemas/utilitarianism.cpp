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
#define INF (1LL<<40)
#define MAX (int) (3e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, k, a, b, c;
vector<par> grafo[MAX];
par dp[MAX][2];

par opt(int u, int p, ll c)
{
	par sum = {0, 0}, best = {0, 0};
	for (auto[v, w] : grafo[u])
	{
		if (v==p) continue;
		opt(v, u, c);
		sum.first += dp[v][0].first, sum.second += dp[v][0].second;
		best = max(best, {dp[v][1].first - dp[v][0].first + w - c, -(dp[v][1].second - dp[v][0].second + 1)});
	}

	dp[u][1] = sum;
	dp[u][0].first = sum.first+best.first, dp[u][0].second = sum.second-best.second;

	return max(dp[u][1], dp[u][0]);
}

int main()
{_
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	if (opt(1, 0, -INF).second < k) 
	{
		cout << "Impossible" << endl;
		return 0;
	}

	ll ini = -INF, meio, fim = INF;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (opt(1, 0, meio).second <= k) fim = meio - 1;
		else ini = meio + 1;
	}

	par resp = opt(1, 0, fim+1);
	cout << resp.first + (k*(fim+1)) << endl; 
}













