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
#define MAX (int) (1<<20)
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

ll tin[MAX], tout[MAX], t, n, m, op, a, b, ft[MAX], val[MAX];
vector<int> grafo[MAX];

void dfs(int u, int p)
{
	tin[u] = ++t;
	for (int v : grafo[u])
		if (v != p) dfs(v, u);
	tout[u] = ++t;
}

ll query(int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, int val)
{
	while (idx <= 2*n)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		update(tin[i], val[i]);
	}

	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b;
			update(tin[a], b - val[a]);
			val[a] = b;
		}
		else
		{
			cin >> a;
			cout << query(tout[a]) - query(tin[a]-1) << endl;
		}
	}
}















