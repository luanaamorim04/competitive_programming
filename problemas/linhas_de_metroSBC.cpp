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
#include <stdio.h>
#define ll long long
#define INF (1e9)
#define MAX (1<<20)
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

int pai[MAX], st[MAX], lazy[MAX], sub[MAX], pos[MAX], h[MAX], n, m, a, b, c, d, t;
vector<int> grafo[MAX];

void push(int idx, int i, int j)
{
	if (!lazy[idx]) return;
 	st[idx] += ((j-i+1)*lazy[idx]);
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}
	lazy[idx] = 0;
}

int query_seg(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	int x = query_seg(esq(idx), i, mid, l, r);
	int y = query_seg(dir(idx), mid+1, j, l, r);
	return x+y;
}

void update_seg(int idx, int i, int j, int l, int r, int val)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] += val;
		push(idx, i, j);
		return;
	}
	int mid = ((i+j)>>1);
	update_seg(esq(idx), i, mid, l, r, val);
	update_seg(dir(idx), mid+1, j, l, r, val);
	st[idx] = st[esq(idx)]+st[dir(idx)];
}

void update(int a, int b, int val)
{
	for (; h[a] != h[b]; a = pai[h[a]])
	{
		if (pos[a] < pos[b]) swap(a, b);
		update_seg(1, 1, n, pos[h[a]], pos[a], val);
	}

	if (pos[a] < pos[b]) swap(a, b);
	update_seg(1, 1, n, pos[b], pos[a], val);
}

int query(int a, int b)
{
	int resp = 0;
	for (; h[a] != h[b]; a = pai[h[a]])
	{
		if (pos[a] < pos[b]) swap(a, b);
		resp += query_seg(1, 1, n, pos[h[a]], pos[a]);
	}
	
	if (pos[a] < pos[b]) swap(a, b);	
	return resp + query_seg(1, 1, n, pos[b], pos[a]);
}

void dfs(int u, int p = -1)
{
	sub[u] = 1;
	for (int &v : grafo[u])
	{
		if (v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
		if (sub[v] >= sub[grafo[u][0]]) swap(v, grafo[u][0]);
	}
}

void build_hld(int u, int p = 0)
{
	pai[u] = p, pos[u] = ++t;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		h[v] = (v == grafo[u][0] ? h[u] : v);
		build_hld(v, u); 
	}
}

int main()
{
	scanf("%i %i", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%i %i", &a, &b);
		grafo[a].emplace_back(b);
		grafo[b].emplace_back(a);
	}

	dfs(1);
	h[1] = 1;
	t = 0;
	build_hld(1);

	while (m--)
	{
		scanf("%i %i %i %i", &a, &b, &c, &d);
		update(a, b, 1);
		printf("%i\n", query(c, d));
		update(a, b, -1);
	}
	return 0;
}











