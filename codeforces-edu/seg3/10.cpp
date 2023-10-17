#include <iostream>
#define MAXN (int) (2e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define INF (int) 1e9

using namespace std;

int n, resp[MAXN], arr[MAXN], pos[MAXN], st[MAXN<<2], prox[MAXN], p[MAXN];

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] = val;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= 2*n; i++)
	{
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	for (int i = 1; i <= 2*n; i++)
	{
		if (i == pos[arr[i]]) prox[i] = INF;
		else prox[i] = pos[arr[i]], p[arr[i]] = i;
	}
	
	for (int i = 1; i <= 2*n; i++)
	{
		if (prox[i] == INF)
		{
			resp[arr[i]] += query(1, 1, 2*n, 1, i-1);
			continue;
		}
		update(1, 1, 2*n, prox[i], 1);
		resp[arr[i]] = -query(1, 1, 2*n, 1, prox[i]-1);
	}

	for (int i = 1; i <= n; i++)
	{
		
		cout << resp[i] << ' ';
	}
	cout << endl;

}
