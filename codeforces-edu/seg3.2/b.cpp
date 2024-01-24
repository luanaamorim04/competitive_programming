#include <iostream>
#define MAXN (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

int st[MAXN<<2], m, n, op, l, r, a, b;
pair<int, int> lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if(lazy[idx].first == lazy[idx].second == 0) return;
	int a1 = lazy[idx].second, an = lazy[idx].second*(j-i+1);
	st[idx] = ((a1+an) * (j-i+1))>>1;
	if (i != j)
	{
		lazy[esq(idx)].first += lazy[idx].first;
		lazy[dir(idx)].first += lazy[idx].first;
		lazy[esq(idx)].second += lazy[idx].second;
		lazy[dir(idx)].second += (lazy[idx].second*(((j+i)>>1)+1))>>1;
	}

	lazy[idx] = {0, 0};
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

void update(int idx, int i, int j, int l, int r, int a, int b)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx].second = b;
		lazy[idx].first = a;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, a, b);
	update(dir(idx), mid+1, j, l, r, a, b);
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
			update(1, 1, n, l, r, a, b);
		}	
		else
		{
			cin >> l;
			cout << query(1, 1, n, l, l) << endl;
		}
	}
}
