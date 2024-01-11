#include <iostream>
#include <string.h>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (1e5 + 10)

using namespace std;

struct preg
{
	int flag, seta, soma;
};
int n, m, op, l, r, v, st[MAXN<<2];
preg lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if (lazy[idx].seta == -1 && lazy[idx].soma == 0) return;
	if (lazy[idx].seta != -1) st[idx] = (j-i+1)*lazy[idx].seta;
	else st[idx] += (j-i+1)*lazy[idx].soma;
	int mid = (j+i)/2;
	if (i != j)
	{
		if (lazy[idx].seta != -1)
		{
			push(esq(idx), i, mid);
			push(dir(idx), mid+1, j);

		}
		lazy[esq(idx)].seta = lazy[dir(idx)].seta = lazy[idx].seta;
		lazy[esq(idx)].soma += lazy[idx].soma;
		lazy[dir(idx)].soma += lazy[idx].soma;
		lazy[esq(idx)].flag |= lazy[idx].flag;
		lazy[dir(idx)].flag |= lazy[idx].flag;
	}
	lazy[idx].seta = -1, lazy[idx].soma = lazy[idx].flag = 0;
}

void update(int idx, int i, int j, int l, int r, int v, int flag)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		if (flag) lazy[idx].soma = 0, lazy[idx].seta = v, lazy[idx].flag = 1;
		else lazy[idx].soma = v;
		push(idx, i, j);
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, v, flag);
	update(dir(idx), mid+1, j, l, r, v, flag);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

int main()
{	
	cin >> n >> m;

	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> l >> r >> v;
			update(1, 1, n, l, r, v, 1);
		}
		if (op == 2)
		{
			cin >> l >> r >> v;
//			update(1, 1, n, l, r, v, 0);
		}
		if (op == 3)
		{
			cin >> l >> r;
//			cout << query(1, 1, n, l, r) << endl;
		}
	}
}
