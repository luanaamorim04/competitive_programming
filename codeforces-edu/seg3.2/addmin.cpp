#include <iostream>
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (2e5 + 1)
#define INF (int) (1e17)

using namespace std;

int n, m, op, l, r, v, st[MAXN<<2], lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if (lazy[idx] == 0) return;
	st[idx] += lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}

	lazy[idx] = 0;
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
	st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return INF;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return min(x, y);
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> op >> l >> r;
		if (op&1)
		{
			cin >> v;
			update(1, 1, n, l+1, r, v);
		}
		else cout << query(1, 1, n, l+1, r) << endl;
	}
}
