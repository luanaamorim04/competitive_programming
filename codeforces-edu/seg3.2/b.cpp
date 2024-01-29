#include <iostream>
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

struct tree
{
	int a1, r, c;
};
int st[MAXN<<2], m, n, op, l, r, a, b;
tree lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if(lazy[idx].r == 0 && lazy[idx].a1 == 0 && lazy[idx].c == 0) return;
	int a1 = lazy[idx].a1;
    int	an = a1 + lazy[idx].r*(j-i);
	st[idx] += (((a1+an) * (j-i+1))/2) + lazy[idx].c*(j-i+1);
	int mid = (i+j)>>1;
	if (i != j)
	{
		lazy[esq(idx)].c += lazy[idx].c;
		lazy[dir(idx)].c += lazy[idx].c;
		lazy[esq(idx)].r += lazy[idx].r;
		lazy[dir(idx)].r += lazy[idx].r;
		lazy[esq(idx)].a1 += lazy[idx].a1;
		lazy[dir(idx)].a1 += lazy[idx].a1 + (lazy[idx].r*(mid+1-i));
	}

	lazy[idx] = {0, 0, 0};
}

int query(int idx, int i, int j, int pos)
{
	push(idx, i, j);
	if (i == j) return st[idx];
	int mid = (i+j)>>1;
	if (pos <= mid) return query(esq(idx), i, mid, pos);
	return query(dir(idx), mid+1, j, pos);
}

void update(int idx, int i, int j, int l, int r, int a1, int ra, int c)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx].a1 = a1 + (ra*(i-l)), lazy[idx].c = c, lazy[idx].r = ra;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, a1, ra, c);
	update(dir(idx), mid+1, j, l, r, a1, ra, c);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> op;
	   	if (op == 1) 
		{
			cin >> l >> r >> a >> b;
			update(1, 1, n, l, r, 0, b, a);
		}	
		else
		{
			cin >> l;
			cout << query(1, 1, n, l) << endl;
		}
	}
}
