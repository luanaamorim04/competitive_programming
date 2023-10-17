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
	int soma;	
};

int n, m, arr[MAXN], a, b, op;
tree st[MAXN<<2];

tree join(tree esq, tree dir)
{
	tree resp;
	resp.soma = esq.soma + dir.soma;
	return resp;
}

void build(int idx, int i, int j)
{
    if (i == j)
    {
		st[idx].soma = arr[i];
		return;
    }
    int mid = (i+j)/2;
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos)
{
    if (i == j)
    {
		st[idx].soma ^= 1;
		return;
    }
    int mid = (i+j)/2;
    if (pos <= mid)update(esq(idx), i, mid, pos);
    else update(dir(idx), mid+1, j, pos);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int k)
{
	if (i == j) return i;
    int mid = (i+j)/2;
	if (k <= st[esq(idx)].soma) return query(esq(idx), i, mid, k);
	return query(dir(idx), mid+1, j, k-st[esq(idx)].soma);
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
		cin >> op >> a;
		if (op&1) update(1, 1, n, a+1);
		else cout << query(1, 1, n, a+1) - 1 << endl;
    }
}
