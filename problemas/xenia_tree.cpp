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
#define MAXL 20
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, sub[MAX], up[MAX][MAXL], pai[MAX], tin[MAX], tout[MAX], t, dist[MAX], vis[MAX], resp[MAX];
vector<int> grafo[MAX];

void dfs(int u, int p = 0)
{
	dist[u] = dist[p] + 1;
	tin[u] = ++t;
	up[u][0] = p;
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];

	for (int v : grafo[u])
	{
		if (v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
	}

	tout[u] = ++t;
}

int is_anc(int u, int v)
{
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v)
{
	if (is_anc(u, v)) return u;
	if (is_anc(v, u)) return v;

	for (int i = MAXL-1; i >= 0; i--)
		if (!is_anc(up[v][i], u)) v = up[v][i];

	return up[v][0];
}

int sz(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (int v : grafo[u])
		if (v != p) sub[u] += sz(v, u);
	return sub[u];
}

int centroid(int u, int p, int tam)
{
	for (int v : grafo[u])
	{
		if (v==p || vis[v]) continue;
		if (sub[v]>tam/2) return centroid(v, u, tam);
	}
	
	return u;
}

void build(int u, int p)
{
	sz(u);
	int k = centroid(u, 0, sub[u]);
	pai[k] = p;
	vis[k] = 1;
	for (int v : grafo[k])
		if (!vis[v]) build(v, k);
}	

int d(int a, int b)
{
	return dist[a] + dist[b] - (2*dist[LCA(a, b)]);
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		resp[i] = MAX;
	}

	resp[n] = MAX;

	tin[0] = ++t;
	dfs(1);
	tout[0] = ++t;

	build(centroid(1, 0, n), 0);

	b = 1;
	while (b)
	{
		resp[b] = min(resp[b], d(1, b));
		b = pai[b];
	}


	while (m--)
	{
		int op, a, b, ans = MAX;
		cin >> op >> a;
		if (op&1) //update
		{
			b = a;
			while (b)
			{
				resp[b] = min(resp[b], d(a, b));
				b = pai[b];
			}
		}
		else
		{
			b = a;
			while (b)
			{
				ans = min(ans, resp[b] + d(a, b));
				b = pai[b];
			}

			cout << ans << endl;
		}
	}
}
















