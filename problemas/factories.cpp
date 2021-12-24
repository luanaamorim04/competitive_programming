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
#include "factories.h"
#define ll long long
#define INF (ll) (1e17)
#define MAXL 21
#define MAX (int) (1e6 + 5)
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

//lca

int up[MAX][MAXL], tin[MAX], tout[MAX], t;
ll nivel[MAX];
vector<par> grafo[MAX];

void dfs(int u, int p = 0)
{
	up[u][0] = p;
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];
	tin[u] = ++t;
	for (auto[v, w] : grafo[u])
	{
		if (v==p) continue;
		nivel[v] = nivel[u] + w;
		dfs(v, u);
	}

	tout[u] = ++t;
}

int anc(int u, int v)
{
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int LCA(int u, int v)
{
	if (anc(u, v)) return u;
	if (anc(v, u)) return v;

	for (int i = MAXL-1; i >= 0; i--)
		if (!anc(up[v][i], u) && up[v][i]) v = up[v][i];
	return up[v][0];
}

ll dist(int u, int v)
{
	return (nivel[u] + nivel[v] - (nivel[LCA(u, v)]<<1));
}

//centroid

bitset<MAX> vis;
int pai[MAX], sub[MAX];

int tam(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (auto[v, w] : grafo[u])
		if (v!=p) sub[u] += tam(v, u);
	return sub[u];
}

int centroid(int u, int p, int t)
{
	for (auto[v, w] : grafo[u])
		if (!vis[v] && v!=p && sub[v]>(t>>1)) return centroid(v, u, t);
	return u;
}

void build(int u, int p = 0)
{
	tam(u);
	int c = centroid(u, 0, sub[u]);
	vis[c] = 1, pai[c] = p;

	for (auto[v, w] : grafo[c])
		if (!vis[v]) build(v, c);
}

//problem

ll resp[MAX];

void ini(int u)
{
	int k = u;
	while (k)
	{ 
		resp[k] = INF;
		k = pai[k];
	}		
}

void update(int u)
{
	int k = u;
	while (k)
	{ 
		resp[k] = min(resp[k], dist(u, k));
		k = pai[k];
	}	
}	

ll query(int u)
{
	ll k = u, r = INF;
	while (k)
	{ 
		r = min(r, dist(u, k) + resp[k]);
		k = pai[k];
	}

	return r;
}

void Init(int n, int a[], int b[], int d[])
{
	for (int i = 0; i < n-1; i++)
	{
		grafo[a[i]+1].push_back({b[i]+1, d[i]});
		grafo[b[i]+1].push_back({a[i]+1, d[i]});
	}

	dfs(1);
	build(1);

	for (int i = 0; i < MAX; i++)
		resp[i] = INF;
}

ll Query(int s, int a[], int t, int b[])
{
	ll r = INF;

	for (int i = 0; i < s; i++)
		update(a[i]+1);

	for (int i = 0; i < t; i++)
		r = min(r, query(b[i]+1));

	for (int i = 0; i < s; i++)
		ini(a[i]+1);

	return r;
}











