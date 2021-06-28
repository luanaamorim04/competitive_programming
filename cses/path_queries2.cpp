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
#define MAXN (int) (2e5 + 5)
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

int tam[MAXN], sub[MAXN], h[MAXN], arr[MAXN], v[MAXN], pai[MAXN], pos[MAXN], t, n, m, a, b, op, k;
vector<int> grafo[MAXN], st[MAXN];

void build_seg(int idx, int i, int j, int k)
{
	if (i == j)
	{
		st[k][idx] = arr[i+pos[k]-1];
		return;
	}

	int mid = ((i+j)>>1);
	build_seg(esq(idx), i, mid, k);
	build_seg(dir(idx), mid+1, j, k);
	st[k][idx] = max(st[k][esq(idx)], st[k][dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val, int k)
{
	if (i == j) 
	{
		st[k][idx] = val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val, k);
	else update(dir(idx), mid+1, j, pos, val, k);
	st[k][idx] = max(st[k][esq(idx)], st[k][dir(idx)]);
}

int query_seg(int idx, int i, int j, int l, int r, int k)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[k][idx];

	int mid = ((i+j)>>1);
	int x = query_seg(esq(idx), i, mid, l, r, k);
	int y = query_seg(dir(idx), mid+1, j, l, r, k); 
	return max(x, y);
}

void dfs(int u, int p)
{
	sub[u] = 1;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		int &v = grafo[u][i];
		if (v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
		if (sub[v] >= sub[grafo[u][0]]) swap(v, grafo[u][0]);
	}
}

void build_hld(int u, int p)
{
	pai[u] = p, pos[u] = ++t, arr[t] = v[u], tam[h[u]]++;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		int &v = grafo[u][i];
		if (v == p) continue;
		h[v] = (!i ? h[u] : v);
		build_hld(v, u);
	}
}

void build()
{
	dfs(1, 0);
	h[1] = 1, k = t = 0;
	build_hld(1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (h[i] == i) 
		{
			st[i].resize(tam[i]<<2);
			build_seg(1, 1, tam[i], i);
		}
	}
}

int query(int a, int b)
{
	if (pos[a] < pos[b]) swap(a, b);
	if (h[a] == h[b]) return query_seg(1, 1, tam[h[a]], pos[b]-pos[h[a]]+1, pos[a]-pos[h[a]]+1, h[a]);
	return max(query_seg(1, 1, tam[h[a]], 1, pos[a]-pos[h[a]]+1, h[a]), query(pai[h[a]], b));
}

int main()
{
	scanf("%i %i", &n, &m);
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		scanf("%i %i", &a, &b);
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	build();
	while (m--)
	{
		scanf("%i %i %i", &op, &a, &b);
		if (op == 1) update(1, 1, tam[h[a]], pos[a]-pos[h[a]]+1, b, h[a]);
		else printf("%i ", query(a, b));
	}
	printf("\n");
}







