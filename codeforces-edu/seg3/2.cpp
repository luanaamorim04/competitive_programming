#include <iostream>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int n, m, arr[MAXN], st[MAXN<<2], a, b, op;

void build(int idx, int i, int j)
{
    if (i == j)
    {
	st[idx] = arr[i];
	return;
    }
    int mid = (i+j)/2;
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
    if (i == j)
    {
	st[idx] = val;
	return;
    }
    int mid = (i+j)/2;
    if (pos <= mid)update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int l, int r)
{
    if (i > r || j < l) return INF;
    if (i >= l && j <= r) return st[idx];
    int mid = (i+j)/2;
    int x = query(esq(idx), i, mid, l, r);
    int y = query(dir(idx), mid+1, j, l, r);
    return min(x, y);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
	cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
	cin >> op >> a >> b;
	if (op&1) update(1, 1, n, a+1, b);
	else cout << query(1, 1, n, a+1, b) << endl;
    }
}
