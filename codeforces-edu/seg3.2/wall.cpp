#include <iostream>
#define INF (int)(1e9)
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int st[MAXN<<2], n, q, op, l, r, h;
struct tree
{
	int least, most, pref;
};

tree lazy[MAXN<<2];

void push(int idx, int i, int j)
{
	if (lazy[idx].pref == -1) return;

	printf("now: lazy[%d - %d] = {%d, %d}\n", i, j, lazy[idx].least, lazy[idx].most);
	if (lazy[idx].pref == 1) st[idx] = max(st[idx], lazy[idx].least);
	else st[idx] = min(st[idx], lazy[idx].most);


//	printf("before: \nlazy[%d - %d] = {%d, %d}\nlazy[%d - %d] = {%d, %d}\n", i, (i+j)/2, lazy[esq(idx)].least, lazy[esq(idx)].most, (i+j)/2 + 1, j, lazy[dir(idx)].least, lazy[dir(idx)].most);
	if (i != j)
	{
		if (lazy[esq(idx)].pref == 1) // adicionando
		{
			lazy[esq(idx)].least = max(lazy[esq(idx)].least, lazy[idx].least);
			if (lazy[idx].most < lazy[esq(idx)].least) lazy[esq(idx)].least = lazy[idx].most, lazy[esq(idx)].pref = 0;
			lazy[esq(idx)].most = lazy[idx].most;
		}
		else //tirando
		{
			lazy[esq(idx)].most = min(lazy[esq(idx)].most, lazy[idx].most);
			if (lazy[idx].least > lazy[esq(idx)].most) lazy[esq(idx)].most = lazy[idx].least, lazy[esq(idx)].pref = 1;
			lazy[esq(idx)].least = lazy[idx].least;
		}

		if (lazy[dir(idx)].pref == 1) // adicionando
		{
			lazy[dir(idx)].least = max(lazy[dir(idx)].least, lazy[idx].least);
			if (lazy[idx].most < lazy[dir(idx)].least) lazy[dir(idx)].least = lazy[idx].most, lazy[dir(idx)].pref = 0;
			lazy[dir(idx)].most = lazy[idx].most;
		}
		else //tirando
		{
			lazy[dir(idx)].most = min(lazy[dir(idx)].most, lazy[idx].most);
			if (lazy[idx].least > lazy[dir(idx)].most) lazy[dir(idx)].most = lazy[idx].least, lazy[dir(idx)].pref = 1;
			lazy[dir(idx)].least = lazy[idx].least;
		}
	}
//	printf("after: \nlazy[%d - %d] = {%d, %d}\nlazy[%d - %d] = {%d, %d}\n", i, (i+j)/2, lazy[esq(idx)].least, lazy[esq(idx)].most, (i+j)/2 + 1, j, lazy[dir(idx)].least, lazy[dir(idx)].most);

	lazy[idx] = {0, INF, -1};
}

void update(int idx, int i, int j, int op, int l, int r, int h)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		if (op == 1) //at least
		{
			lazy[idx].least = h;
			lazy[idx].pref = 1;
			push(idx, i, j);
		}
		else //at most
		{
			lazy[idx].most = h;
			lazy[idx].pref = 0;
			push(idx, i, j);
		}

		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, op, l, r, h);
	update(dir(idx), mid+1, j, op, l, r, h);
}

int query(int idx, int i, int j, int pos)
{
	push(idx, i, j);
	if (i == j) return st[idx];
	int mid = (i+j)>>1;
	if (pos <= mid) return query(esq(idx), i, mid, pos);
	return query(dir(idx), mid+1, j, pos);
}

int main()
{
	cin >> n >> q;
	for (int i = 0; i < MAXN*4; i++)
		lazy[i] = {0, 0, -1};

	while (q--)
	{
		cin >> op >> l >> r >> h;
		update(1, 0, n-1, op, l, r, h);
	}

	for (int i = 0; i < n; i++)
		cout << query(1, 0, n-1, i) << endl;
}
