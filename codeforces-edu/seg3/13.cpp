#include <iostream>
#define MAXN (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int n, arr[MAXN], q, op, l, r, st[MAXN<<2][2];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx][1] = arr[i]*((i&1) ? -1 : 1);
		st[idx][0] = -st[idx][1];
		return;
	}	
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx][0] = st[esq(idx)][0] + st[dir(idx)][0];
	st[idx][1] = st[esq(idx)][1] + st[dir(idx)][1];
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx][1] = val*((i&1) ? -1 : 1);
		st[idx][0] = -st[idx][1];
		return;
	}	
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx][0] = st[esq(idx)][0] + st[dir(idx)][0];
	st[idx][1] = st[esq(idx)][1] + st[dir(idx)][1];
}


int query(int idx, int i, int j, int l, int r, int flag)
{
	if (i > r || j < l) return 0;
   	if (i >= l && j <= r) return st[idx][flag];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r, flag);
	int y = query(dir(idx), mid+1, j, l, r, flag);
	return x+y;	
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	cin >> q;
	while (q--)
	{
		cin >> op >> l >> r;
		if (op&1) cout << query(1, 1, n, l, r, !(l&1)) << endl;
		else update(1, 1, n, l, r);
	}
}
