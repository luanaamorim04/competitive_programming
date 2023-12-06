#include <bits/stdc++.h>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (1e5 + 10)
#define INF (int) (1e9 + 10)
#define int long long

using namespace std;

struct tree
{
	int pref, suff, resp, tot;
};

tree st[MAXN<<2];
int lazy[MAXN<<2];
int n, m, op, l, r, v, i;

/*
   Solves the problem. For real.
   @author passivinho
 */

void push(int idx, int i, int j)
{
	if (lazy[idx] == -INF) return;
	st[idx].tot = lazy[idx]*(j-i+1);
	st[idx].pref = st[idx].suff = st[idx].resp = max(st[idx].tot, 0LL);
	if (i != j)
	{
		lazy[esq(idx)] = lazy[idx];
		lazy[dir(idx)] = lazy[idx];
	}

	lazy[idx] = -INF;
}

tree join(tree esq, tree dir)
{
	tree r;
	r.tot = esq.tot + dir.tot;
	r.pref = max(esq.pref, esq.tot + dir.pref);
	r.suff = max(dir.suff, dir.tot + esq.suff);
	r.resp = max({esq.resp, dir.resp, esq.suff + dir.pref});
	return r;
}

void update(int idx, int i, int j, int l, int r, int v)
{	
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = v;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, v);
	update(dir(idx), mid+1, j, l, r, v);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

//tree query(int idx, int i, int j)
//{
//	push(idx, i, j);
//	if (i > r || j < l) return {0, -INF, -INF, -INF};
//	if (i >= l && j <= r) return st[idx];
//	int mid = (i+j)>>1;
//	tree x = query(esq(idx), i, mid);
//	tree y = query(dir(idx), mid+1, j);
//	return join(x, y);
//}
//
int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i < MAXN*4; i++)
		lazy[i] = -INF;
	while (m--)
	{
		cin >> l >> r >> v;
		update(1, 0, n-1, l, r-1, v);
		cout << st[1].resp << endl;
	}
}
