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
#define MAX (int) (2e5 + 5)
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

vector<ll> grafo[1<<20], v;
ll n, a, b, val[1<<20], ini[1<<20], fim[1<<20], maxn, ft[1<<20], op, m;

ll query(int idx)
{
	ll ans = 0;
	idx++;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, ll val)
{
	idx++;
	while (idx <= maxn)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

void dfs(int u, int p)
{
	v.push_back(u);
	ini[u] = maxn++;
	for (int v : grafo[u])
		if (v != p) dfs(v, u);

	v.push_back(u);
	fim[u] = maxn++;
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> val[i];

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1, 0);
	for (int u = 1; u <= n; u++)
	{
		update(ini[u], val[u]);
		update(fim[u], -val[u]);
	}

	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b;
			update(ini[a], b - val[a]);
			update(fim[a], -b + val[a]);
			val[a] = b;
		}	
		else
		{
			cin >> a;
			cout << query(ini[a]) << endl;
		}	
	}
}













