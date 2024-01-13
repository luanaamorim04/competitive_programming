#include <iostream>
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (2e5 + 1)
#define INF (int) (1e17)
#define MOD (int) (1e9 + 7)

using namespace std;

int n, m, op, l, r, v, st[MAXN<<2], lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if (lazy[idx] == 1) return;
	st[idx] = (st[idx] * lazy[idx]) % MOD;
	if (i != j)
	{
		lazy[esq(idx)] = (lazy[esq(idx)] * lazy[idx]) % MOD;
		lazy[dir(idx)] = (lazy[dir(idx)] * lazy[idx]) % MOD;
	}

	lazy[idx] = 1;
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
	st[idx] = (st[esq(idx)]+st[dir(idx)]) % MOD;
}

int query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return (x+y)%MOD;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = 1;
		return;
	}
	int mid = (i+j)>>1;	
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i < MAXN*4; i++)
		lazy[i] = 1;
	build(1, 1, n);
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
