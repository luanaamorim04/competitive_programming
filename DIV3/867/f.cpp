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
#define int long long
#define INF (1e9)
#define MAX (int) (2e5 + 2)
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
#define mp(a, b) make_pair(a, b)

using namespace std;

int n, t, k, c, dist[MAX], m, maior, maior2, vis[MAX], a, b;
vector<int> grafo[MAX];

int dfs(int u, int p, int d)
{
	// dbug(u);
	// dbug(p);
	// dbug(d);
	// cout << endl;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		vis[u] |= dfs(v, u, d+1);
	}

	if (d == maior2) vis[u] = 1;
	printf("vis[%d] = %d\n", u, vis[u]);
	return vis[u];
}

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> c;
		dist[0] = -1;
		for (int i = 1; i <= n; i++)
		{
			vis[i] = dist[i] = 0;
			grafo[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
			vis[i] = 0;
		}
		vis[n] = 0;

		queue<par> fila;
		fila.push(mp(1LL, 0LL));
		while (!fila.empty())
		{
			int u = fila.front().first; int p = fila.front().second; fila.pop();
			dist[u] = dist[p] + 1;
			m = u;
			maior = dist[u];
			for (int v : grafo[u])
			{
				if (v == p) continue;
				fila.push(mp(v, u));
			}
		}

		// dbug(maior);

		if (c > k) 
		{
			cout << maior*k << endl;
			continue; 
		}

		fila.push(mp(m, 0LL));
		while (!fila.empty())
		{
			int u = fila.front().first; int p = fila.front().second; fila.pop();
			dist[u] = dist[p] + 1;
			maior2 = dist[u];
			for (int v : grafo[u])
			{
				if (v == p) continue;
				fila.push(mp(v, u));
			}
		}

		// dbug(maior2);

		dfs(m, 0LL, 0);

		fila.push(mp(1LL, 0LL));
		while (!fila.empty())
		{
			int u = fila.front().first; int p = fila.front().second; fila.pop();
			dist2[u] = dist2[p] + 1;
			if (vis[u] == 1)
			{
				dbug(u);
				dbug(dist2[u]);
				cout << (maior2*k) - ((min+dist2[u])*c) << endl;
				break;
			}
			for (int v : grafo[u])
			{
				if (v == p) continue;
				fila.push(mp(v, u));
			}
		}

		// dbug(dist[1]);
	}
}


