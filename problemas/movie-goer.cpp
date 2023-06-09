#include <bits/stdc++.h>
#include <iostream>
#define MAXN (int) (1e6 + 5)
#define int long long
#define lsb(x) (x&(-x))
#define par pair<int, int> 
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int n, m, arr[MAXN], val[MAXN], resp, last[MAXN], lastlast[MAXN];
par st[MAXN<<2];

par join(par esq, par dir)
{
	return {max(dir.first, dir.second + esq.first), esq.second + dir.second};
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] = {val, val};
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	for (int i = 1; i <= m; i++)
		cin >> val[i];

	for (int r = 1; r <= n; r++)
	{
		if (lastlast[arr[r]]) update(1, 1, n, lastlast[arr[r]], 0);
		if (last[arr[r]]) update(1, 1, n, last[arr[r]], -val[arr[r]]);
		update(1, 1, n, r, val[arr[r]]);

		resp = max(resp, st[1].first);
		lastlast[arr[r]] = last[arr[r]];
		last[arr[r]] = r;
	}

	cout << resp << endl;
}