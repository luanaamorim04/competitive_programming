#include <iostream>
#define MAXN (int) (1e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

struct tree
{
	int freq[45], resp; 
};

tree st[MAXN<<2], vazio;
int n, q, arr[MAXN], op, l, r;

tree join(tree esq, tree dir)
{
	tree r;
	r.resp = 0;
	for (int i = 0; i <= 40; i++)
	{
		r.freq[i] = esq.freq[i] + dir.freq[i];
		r.resp += (r.freq[i] != 0);
	}
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].freq[arr[i]] = 1;
		st[idx].resp = 1;
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
		for (int i = 0; i <= 40; i++) st[idx].freq[i] = 0;
		st[idx].freq[val] = 1;
		st[idx].resp = 1;
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
