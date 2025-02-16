//#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int q, k, n, arr[MAXN], freq[MAXN];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = freq[i];
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = max(st[esq(idx)], st[dir(idx)]);
}

void push(int idx, int i, int j)
{
	if (!lazy[idx]) return;
	st[idx] = st[idx]^lazy[idx];
	if (i != j)
}

void update(int idx, int i, int j, int l, int r, int x)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = x;
		push(idx, i, j);
		return;
	};
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, x);
	update(dir(idx), mid+1, j, l, r, x);
	push(esq(idx), i, mid);
	push(dir(idx), mid+1, j);
	st[idx] = max(st[esq(idx)], st[dir(idx)]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	while (k--)
	{
		cin >> n >> q;
		int x = 0;
		for (int i = 1; i <= n; i++) 
		{
			cin >> arr[i];
		}
		for (int i = n; i >= 1; i--) 
			freq[i] = freq[i+1]^arr[i];
		for (int i = n; i >= 1; i--) 
			freq[i] = max(freq[i], freq[i+1]);

		while (q--)
		{
			int t;
			cin >> t;
			int ini = 1, meio, fim = n;
			while (ini <= fim)
			{
				meio = (ini+fim)>>1;
				if (freq[meio] <= t) fim = meio - 1;
				else ini = meio + 1;
			}
			cout << fim + 1 << ' ';
		}
		cout << endl;
		for (int i = 1; i <= n; i++) freq[i] = 0;
	}
}
