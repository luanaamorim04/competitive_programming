#include <iostream>
#define MAXN (int) (1e5 + 10)
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

struct tree
{
	int soma, seta, vazio;
};

tree lazy[MAXN<<2], vazio;
int st[MAXN<<2], n, m, op, l, r, v;

void push(int idx, int i, int j)
{
	if (lazy[idx].vazio) return;
	st[idx] += (j-i+1)*lazy[idx].soma;
	if (lazy[idx].seta != -1) st[idx] = (j-i+1)*lazy[idx].seta;

	if (i != j)
	{
		lazy[esq(idx)].vazio = lazy[dir(idx)].vazio = 0;
		lazy[esq(idx)].soma += lazy[idx].soma;
		lazy[dir(idx)].soma += lazy[idx].soma;
		if (lazy[idx].seta != -1) lazy[esq(idx)].seta = lazy[dir(idx)].seta = lazy[idx].seta;
		
		if (lazy[esq(idx)].seta != -1 && lazy[idx].seta == -1) lazy[esq(idx)].seta += lazy[idx].soma;
		if (lazy[dir(idx)].seta != -1 && lazy[idx].seta == -1) lazy[dir(idx)].seta += lazy[idx].soma;
	}

	lazy[idx] = vazio;
}

void update(int idx, int i, int j, int l, int r, int v, int flag)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx].vazio = 0;
		if (flag) lazy[idx].seta = v;
		else lazy[idx].soma = v;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, v, flag);
	update(dir(idx), mid+1, j, l, r, v, flag);
	st[idx] = st[esq(idx)]+st[dir(idx)];
//	printf("st[%d - %d] == %d\n", i, j, st[idx]);
}

int query(int idx, int i, int j, int l, int r)
{
//	printf("st[%d - %d] == %d\n", i, j, st[idx]);
	push(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

void dbug(int l, int r)
{
	for (int i = l; i <= r; i++)
		cout << query(1, 1, n, i, i) << endl;
	cout << endl;
}

int32_t main()
{
	cin >> n >> m;
	vazio = {0, -1, 1};
	for (int i = 0; i < MAXN*4; i++)
		lazy[i] = vazio;

	while (m--)
	{
		cin >> op >> l >> r;
		if (op == 1)
		{
			cin >> v;
			update(1, 1, n, l+1, r, v, 1);
		}
		else if (op == 2)
		{
			cin >> v;
			update(1, 1, n, l+1, r, v, 0);
		}
		else
		{
			cout << query(1, 1, n, l+1, r) << endl;
		}
	}
}
