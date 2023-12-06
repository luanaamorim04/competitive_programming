#include <iostream>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (1e5 + 10)
#define INF (int) (1e9 + 10)
#define int long long
#define ii pair<int, int>

using namespace std;

int st[MAXN<<2];
int lazy[MAXN<<2];
int n, m, op, l, r, v, i;

/*
   Solves the problem. For real.
   @author passivinho
*/

void push(int idx, int i, int j)
{
	if (lazy[idx] == 0) return;
	st[idx] = (j-i+1) - st[idx];
	if (i != j)
	{
		lazy[esq(idx)] ^= lazy[idx];
		lazy[dir(idx)] ^= lazy[idx];
	}

	lazy[idx] = 0;
}

void update(int idx, int i, int j, int l, int r)
{	
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] ^= 1;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = st[esq(idx)]+st[dir(idx)];
}

int query(int idx, int i, int j, int k)
{
	while (i != j)
	{	
		push(idx, i, j);
		int mid = (i+j)>>1;
		push(esq(idx), i, mid);
		push(dir(idx), mid+1, j);
		if (st[esq(idx)] >= k) idx = esq(idx), j = mid;
		else k -= st[esq(idx)], idx = dir(idx), i = mid+1;
	}

	return i;
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> op;
		if (op&1) 
		{
			cin >> l >> r;
			update(1, 0, n-1, l, r-1);
		}
		else
		{
			cin >> v;
			cout << query(1, 0, n-1, v+1) << endl;
		}
	}
}
