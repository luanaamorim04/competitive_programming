#include <iostream>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int)(1e5 + 10)

using namespace std;

int n, arr[MAXN], st[MAXN], resp[MAXN];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = 1;
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] = val;
		return;
	}
	int mid = (i+j)>>1;
	if (mid <= pos) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int query(int idx, int i, int j, int val)
{
	cout << i << ' ' << j << ": " << val << endl;
	if (i == j) return i;
	int mid = (i+j)>>1;
	if (st[esq(idx)] >= val) return query(esq(idx), i, mid, val);
	return query(dir(idx), mid+1, j, val-st[esq(idx)]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	for (int i = n; i >= 1; i--)
	{
		resp[i] = query(1, 1, n, i-arr[i]);
		update(1, 1, n, resp[i], 0);
		cout << resp[i] << endl;
	//	break;
	}

	for (int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << endl;
}
