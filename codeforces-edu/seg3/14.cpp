#include <iostream>
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define _ ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct tree
{
	int m[2][2];
};

tree st[MAXN<<2];
int n, p, q, a1[MAXN], a2[MAXN], a3[MAXN], a4[MAXN], l, r;

tree join(tree esq, tree dir)
{
	tree r;
	r.m[0][0] = (esq.m[0][0]*dir.m[0][0] + esq.m[0][1]*dir.m[1][0]) % p;
	r.m[0][1] = (esq.m[0][0]*dir.m[0][1] + esq.m[0][1]*dir.m[1][1]) % p;
	r.m[1][0] = (esq.m[1][0]*dir.m[0][0] + esq.m[1][1]*dir.m[1][0]) % p;
    r.m[1][1] = (esq.m[1][0]*dir.m[0][1] + esq.m[1][1]*dir.m[1][1]) % p;
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {{a1[i], a2[i], a3[i], a4[i]}};
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return {{1, 0, 0, 1}};
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return join(x, y);
}


int32_t main()
{
	scanf("%d%d%d", &p, &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &a1[i], &a2[i], &a3[i], &a4[i]);
	build(1, 1, n);
	while (q--)
	{
		scanf("%d%d", &l, &r);
		tree resp =  query(1, 1, n, l, r);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				printf("%d ", resp.m[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}
