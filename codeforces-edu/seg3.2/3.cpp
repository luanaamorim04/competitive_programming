#include <iostream>
#include <string.h>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (1e5 + 10)
#define int long long

//machucado treina melhor

using namespace std;

int st[MAXN<<2], lazy[MAXN<<2], n, m, op, l, r, v, i;

void push(int idx, int i, int j)
{
	if (lazy[idx] == -1) return;
	st[idx] = lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] = lazy[idx];
		lazy[dir(idx)] = lazy[idx];
	}

	lazy[idx] = -1;
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
	st[idx] = max(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int pos)
{
	push(idx, i, j);
	if (i == j)
	{
		return st[idx];
	}
	int mid = (i+j)>>1;
	if (pos <= mid) return query(esq(idx), i, mid, pos);
	return query(dir(idx), mid+1, j, pos);
}

int32_t main()
{
	cin >> n >> m;
	memset(lazy, -1, sizeof lazy);
	while (m--)
	{
		cin >> op;
		if (op&1) 
		{
			cin >> l >> r >> v;
			update(1, 0, n-1, l, r-1, v);
		}
		else
		{
			cin >> i;
			cout << query(1, 0, n-1, i) << endl;
		}
	}
}
