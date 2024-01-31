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
int arr[MAXN], m, n, op, l, r, a, b;
tree lazy[MAXN<<2];
pair<int, int> st[MAXN<<2];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {arr[i]*i, arr[i]};
		return;
	};
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx].first = st[esq(idx)].first + st[dir(idx)].first;
	st[idx].second = st[esq(idx)].second + st[dir(idx)].second;

}

void push(int idx, int i, int j)
{
	if(lazy[idx].r == 0 && lazy[idx].a1 == 0 && lazy[idx].c == 0) return;
	int a1 = lazy[idx].a1;
    int	an = a1 + lazy[idx].r*(j-i);
	st[idx].first += (((a1+an) * (j-i+1))/2);
	st[idx].second += (j-i+1)*lazy[idx].c;
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

pair<int, int> query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return {0, 0};
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	pair<int, int> x = query(esq(idx), i, mid, l, r);
	pair<int, int> y = query(dir(idx), mid+1, j, l, r);
	return {x.first+y.first, x.second+y.second};
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
	st[idx].first = st[esq(idx)].first + st[dir(idx)].first;
	st[idx].second = st[esq(idx)].second + st[dir(idx)].second;
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);

	while (m--)
	{
		cin >> op;
	   	if (op == 1) 
		{
			cin >> l >> r >> a;
			update(1, 1, n, l, r, a*l, a, a);
		}	
		else
		{
			cin >> l >> r;
			pair<int, int> resp = query(1, 1, n, l, r);
			cout << resp.first - (resp.second*(l-1)) << endl;
		}
	}
}
