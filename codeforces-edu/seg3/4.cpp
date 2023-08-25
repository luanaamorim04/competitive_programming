#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10LL)
#define INF (int) (1e9 + 10LL)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

struct tree
{
	int pref, suff, maior, soma;	
};

int n, m, arr[MAXN], a, b, op;
tree st[MAXN<<2];

tree join(tree esq, tree dir)
{
	tree resp;
	resp.soma = esq.soma + dir.soma;
	resp.pref = max(esq.pref, esq.soma + dir.pref);
	resp.suff = max(dir.suff, dir.soma + esq.suff);
	resp.maior = max({esq.maior, dir.maior, esq.suff + dir.pref});
	return resp;
}

void build(int idx, int i, int j)
{
    if (i == j)
    {
		st[idx] = {max(0LL, arr[i]), max(0LL, arr[i]), max(0LL, arr[i]), arr[i]};
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
		st[idx] = {max(0LL, val), max(0LL, val), max(0LL, val), val};
		return;
    }
    int mid = (i+j)/2;
    if (pos <= mid)update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
    if (i > r || j < l) return {0LL, 0LL, 0LL, 0LL};
    if (i >= l && j <= r) return st[idx];
    int mid = (i+j)/2;
    tree x = query(esq(idx), i, mid, l, r);
    tree y = query(dir(idx), mid+1, j, l, r);
    return join(x, y);
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		cin >> arr[i];
    build(1, 1, n);
	cout << st[1].maior << endl;
    while (m--)
    {
		cin >> a >> b;
		update(1, 1, n, a+1, b);
		cout << st[1].maior << endl;
    }
}
