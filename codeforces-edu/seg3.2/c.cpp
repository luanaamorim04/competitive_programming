#include <iostream>
#include <bits/stdc++.h>
#define esq(x) (x<<1)
#define SOMA (int) (1e6)
#define MAXN (int) (2e6 + 10)
#define dir(x) ((x<<1)|1)

using namespace std;

struct tree
{
	int q, e, d, s;
};

tree st[MAXN<<2];
int n, l, r, lazy[MAXN<<2];
char c;

tree join(tree esq, tree dir)
{
	tree r;
	r.s = esq.s + dir.s;
	r.e = esq.e;
	r.d = dir.d;
	if (!esq.d || !dir.e) r.q = esq.q + dir.q;
	else r.q = esq.q + dir.q - 1;

	return r;
}

void push(int idx, int i, int j)
{
	if (lazy[idx] == -1) return;
	st[idx].s = (lazy[idx] ? j-i+1 : 0);
	st[idx].q = (lazy[idx] == 1);
	st[idx].e = (lazy[idx] == 1);
	st[idx].d = (lazy[idx] == 1);
	if (i != j)
	{
		lazy[esq(idx)] = lazy[dir(idx)] = lazy[idx];
	}

	lazy[idx] = -1;
}

void update(int idx, int i, int j, int l, int r, int flag)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = flag;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, flag);
	update(dir(idx), mid+1, j, l, r, flag);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int32_t main()
{
	cin >> n;
	memset(lazy, -1, sizeof lazy);
	while (n--)
	{
		cin >> c >> l >> r;
		update(1, 0, MAXN-1, l+SOMA, l+r-1+SOMA, c=='B');
		cout << st[1].q << ' ' << st[1].s << endl;
	}
}
