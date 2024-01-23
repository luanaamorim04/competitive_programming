#include <iostream>
#define MAXN (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

void push(int idx, int i, int j)
{
	if (lazy[idx] == 0) return;
	int a1 = lazy[idx], an = lazy[idx]*(j-i+1);
	st[idx] = ((a1+an) * (j-i+1))>>1;
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += (lazy[idx]*(((j+i)>>1)+1))>>1;
	}

	lazy[idx] = 0;
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

void update(int idx, int i, int j, int l, int r, int val)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = val;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> op 
	}
}
