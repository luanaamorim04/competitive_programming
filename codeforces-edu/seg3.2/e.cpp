#include <iostream>
#define MAXN (int) (1e5 + 10)
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define par tuple<int, int, int>
#define INF (int)(1e9)
#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

using namespace std;

struct tree
{
	int menor, maior, last;
};

tree lazy[MAXN<<2], st[MAXN<<2];
int n, m, op, l, r, v;

void push(int idx, int i, int j)
{
	if (lazy[idx].last == -1) return;
	st[idx].menor = max(lazy[idx].menor, st[idx].menor);
	st[idx].maior = min(lazy[idx].maior, st[idx].maior);
	st[idx].last = lazy[idx].last;
	if (i != j)
	{
		if (lazy[idx].maior != INF && lazy[idx].maior < lazy[esq(idx)].menor)
		lazy[esq(idx)].menor = max(lazy[esq(idx)].menor, lazy[idx].menor);
		lazy[esq(idx)].maior = min(lazy[esq(idx)].maior, lazy[idx].maior);
		lazy[dir(idx)].menor = max(lazy[esq(idx)].menor, lazy[idx].menor);
		lazy[dir(idx)].maior = min(lazy[esq(idx)].maior, lazy[idx].maior);
	}

	lazy[idx] = {0, INF, -1};
}

void update(int idx, int i, int j, int l, int r, int flag, int h)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		if (!flag && h < st[idx].menor) lazy[idx].last = 0;
		else lazy[idx].last = 1;
		if (flag) lazy[idx].menor = h;
		else lazy[idx].maior = h;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, flag, h);
	update(dir(idx), mid+1, j, l, r, flag, h);
	st[idx].maior = max(st[esq(idx)].maior, st[dir(idx)].maior);
	st[idx].menor = min(st[esq(idx)].menor, st[dir(idx)].menor);
}

int query(int idx, int i, int j, int pos)
{
	push(idx, i, j);
	if (i == j)
	{
		if (st[idx].menor > st[idx].maior) 
		{
			if (st[idx].last == 1) return st[idx].menor;
			return st[idx].maior;
		}
		return st[idx].menor;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) return query(esq(idx), i, mid, pos);
	return query(dir(idx), mid+1, j, pos);
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i < MAXN*4; i++)
	{
		lazy[i] = {-1, INF, -1};
		st[i].maior = INF;
		st[i].last = 1;
	}

	while (m--)
	{
		cin >> op >> l >> r >> v;
		if (op == 1) update(1, 0, n-1, l, r, 1, v);
		else update(1, 0, n-1, l, r, 0, v);
	}

	for (int i = 0; i < n; i++)
		cout << query(1, 0, n-1, i) << endl;
}
