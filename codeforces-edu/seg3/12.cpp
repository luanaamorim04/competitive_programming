#include <iostream>
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

int n, q, op, l, r, v, st[MAXN<<3];

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] += val;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

int32_t main()
{
	cin >> n >> q;
	while (q--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> l >> r >> v;
			++l, ++r;
			update(1, 1, n<<1, l, v);
			update(1, 1, n<<1, r, -v);
		}
		else
		{
			cin >> v;
			++v;
			cout << query(1, 1, n<<1, 1, v) << endl;
		}
	}
}
