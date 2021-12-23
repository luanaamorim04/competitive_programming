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
#include <fstream>
#define ll long long
#define INF (1e9)
#define MAX (int) (1e5 + 5)
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
#define MAXL 17

using namespace std;

ofstream fout ("newbarn.out");
ifstream fin ("newbarn.in");
int n, q, b, idx, vis[MAX], up[MAX][MAXL], tin[MAX], tout[MAX], t, nivel[MAX], sub[MAX], pai[MAX];
char a;
vector<pair<char, int> > op;
vector<int> grafo[MAX];
tuple<int, int, int, int> resp[MAX];

// dist 

void dfs(int u, int p = 0)
{
	nivel[u] = nivel[p] + 1;
	tin[u] = ++t;
	up[u][0] = p;
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];

	for (int v : grafo[u])
		if (v!=p) dfs(v, u);
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

int dist(int u, int v)
{
	return nivel[u] + nivel[v] - (nivel[LCA(u, v)]<<1);
}

//centroid

int tam(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (int v : grafo[u])
		if (v!=p) sub[u] += tam(v, u);
	return sub[u];
}

int centroid(int u, int p, int t)
{
	for (int v : grafo[u])
		if (!vis[v] && v!=p && sub[v]>(t>>1)) return centroid(v, u, t);
	return u;
}

void build(int u, int p = 0)
{		
	tam(u);
	int c = centroid(u, 0, sub[u]);
	pai[c] = p, vis[c] |= 1;
	for (int v : grafo[c])
		if (!vis[v]) build(v, c);
}	

//problem

void update(int u)
{	
	auto[a, b, c, e] = resp[u];
	int k = u, d;
	resp[u] = {a, b, c, 1};
	// a == maior
	// b == segundo maior
	// c == subarvore de a
	// e == existe

	while (pai[k])
	{
		d = dist(pai[k], u);
		auto[a, b, c, e] = resp[pai[k]];

		if (d >= a)
		{
			if (c==k) resp[pai[k]] = {d, b, k, e};
			else resp[pai[k]] = {d, a, k, e};
		} 
		else if (d > b && c!=k) resp[pai[k]] = {a, d, c, e};
		
		k = pai[k];
	}
}

int query(int u)
{
	auto[a, b, c, e] = resp[u];
	int k = u, r = a, d;
	while (pai[k])
	{
		auto[a, b, c, e] = resp[pai[k]];
			
		if (~e)
		{
			d = dist(pai[k], u);
			if (k == c) r = max(r, b+d);
			else r = max(r, a+d);
		}

		k = pai[k];
	}

	return r;
}

int main()
{_
	fin >> q;
	for (int i = 0; i < q; i++)
	{
		fin >> a >> b;
		op.push_back({a, b});
		if (a == 'B') 
		{
			++idx;
			if (b==-1) continue; 
			grafo[idx].push_back(b);
			grafo[b].push_back(idx);
		}
	}

	for (int i = 1; i <= idx; i++)
	{
		resp[i] = {0, 0, 0, -1};
		if (!nivel[i]) dfs(i);
	}

	for (int i = 1; i <= idx; i++)
		if (!vis[i]) build(i);

	idx = 0;
	for (auto[p, k] : op)
	{
		if (p=='B')
		{
			update(++idx);
		}
		else
		{
			fout << query(k) << endl;
		}
	}
}

















