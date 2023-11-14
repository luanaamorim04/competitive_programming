#include <iostream>
#define MAXN (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long

using namespace std;

struct tree
{
	int resp, freq[45];
};

int arr[MAXN], op, l, r, n, q;
tree st[MAXN<<2], vazio;

tree join(tree esq, tree dir)
{
	int soma = 0;
	tree r;
	r.resp = esq.resp + dir.resp;
	for (int i = 40; i >= 1; i--)
	{
		r.freq[i] = esq.freq[i] + dir.freq[i];
		r.resp += soma*dir.freq[i];
		soma += esq.freq[i];
	}
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].freq[arr[i]] = 1;
		st[idx].resp = 0;
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		for (int i = 1; i <= 40; i++)
			st[idx].freq[i] = 0;
		st[idx].freq[val] = 1;
		st[idx].resp = 0;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return vazio;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return join(x, y);
}

int32_t main()
{
	for (int i = 0; i <= 40; i++)
		vazio.freq[i] = 0;
	vazio.resp = 0;

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);
	while (q--)
	{
		cin >> op >> l >> r;
		if (op&1) cout << query(1, 1, n, l, r).resp << endl;
		else update(1, 1, n, l, r);
	}
}
