//#include <bits/stdc++.h>
#include <iostream>
#define MAXN (int) (2e5 + 10LL)
#define INF (int) (1e9 + 10LL)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
//#define int long long

using namespace std;

struct tree
{
	int maior ;	
};

int n, m, arr[MAXN], a, b, op;
tree st[MAXN<<2];

tree join(tree esq, tree dir)
{
	tree resp;
	resp.maior = max(esq.maior, dir.maior);
	return resp;
}

void build(int idx, int i, int j)
{
    if (i == j)
    {
		st[idx].maior = arr[i];
		return;
    }
    int mid = (i+j)/2;
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
    if (i == j)
    {
		st[idx].maior = val;
		return;
    }
    int mid = (i+j)/2;
    if (pos <= mid)update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree qmaior(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return {0};
	if (i >= l && j <= r) return st[idx];
    int mid = (i+j)/2;
	tree x = qmaior(esq(idx), i, mid, l, r);
	tree y = qmaior(dir(idx), mid+1, j, l, r);
	return join(x, y);
}

int query(int idx, int i, int j, int k, int l)
{
	if (i == j) return i;
	int mid = (i+j)/2;
	if (l > mid) return query(dir(idx), mid+1, j, k, l);
	if (qmaior(1, 1, n, l, mid).maior >= k) return query(esq(idx), i, mid, k, l);
	return query(dir(idx), mid+1, j, k, l);
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
		cin >> op >> a >> b;
		if (op&1) update(1, 1, n, a+1, b);
		else if (a <= qmaior(1, 1, n, b+1, n).maior) cout << query(1, 1, n, a, b+1) - 1 << endl;
    	else cout << -1 << endl;
	}
}
