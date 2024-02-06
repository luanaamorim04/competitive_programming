#include <iostream>
#define endl '\n'
#include <bits/stdc++.h>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (2e5 + 10)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int t, n, arr[MAXN], q, l, r;

struct ii
{
	int maior, menor;
};

ii st[MAXN<<2];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].maior = st[idx].menor = i;
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	int e = arr[st[esq(idx)].maior], d = arr[st[dir(idx)].maior];
	st[idx].maior = (e > d ? st[esq(idx)].maior : st[dir(idx)].maior);
	e = arr[st[esq(idx)].menor], d = arr[st[dir(idx)].menor];
	st[idx].menor = (e < d ? st[esq(idx)].menor : st[dir(idx)].menor);
}

ii query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return {0, n+1};
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	ii x = query(esq(idx), i, mid, l, r);
	ii y = query(dir(idx), mid+1, j, l, r);
	ii ans;
	int e = arr[x.maior], d = arr[y.maior];
	ans.maior = (e > d ? x.maior : y.maior);
	e = arr[x.menor], d = arr[y.menor];
	ans.menor = (e < d ? x.menor : y.menor);
	return ans;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		build(1, 1, n);
		arr[0] = -1e9, arr[n+1] = 1e9;
		cin >> q;
		while (q--)
		{
			cin >> l >> r;
			ii ans = query(1, 1, n, l, r);
			if (ans.maior == ans.menor) cout << -1 << ' ' << -1 << endl;
			else cout << ans.menor << ' ' << ans.maior << endl;
		}
		cout << endl;
	}
}
