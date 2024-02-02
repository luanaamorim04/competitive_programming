#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define int unsigned long long
#define SOMA (int) (1e18) 
#define MAXN (int) (1e5 + 10) 
#define INF (1e18 + 10) 
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define par pair<int, int>
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, st[MAXN<<2][2], range[MAXN], nxt[MAXN], last[MAXN];
long long pos[MAXN];

void update(int idx, int i, int j, int pos, int val, int flag)
{
	if (i == j) 
	{
		st[idx][flag] = val;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val, flag);
	else update(dir(idx), mid+1, j, pos, val, flag);
	st[idx][0] = min(st[esq(idx)][0], st[dir(idx)][0]);
	st[idx][1] = max(st[esq(idx)][1], st[dir(idx)][1]);
}

par query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return {INF, 0};
	if (i >= l && j <= r) return {st[idx][0], st[idx][1]};
	int mid = (i+j)>>1;
	par x = query(esq(idx), i, mid, l, r);
	par y = query(dir(idx), mid+1, j, l, r);
	return {min(x.first, y.first), max(x.second, y.second)};
}

int bb(int dist, int fim)
{
	int ini = 1, meio;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (pos[meio] >= dist) fim = meio - 1;
		else ini = meio + 1;
	}

	return fim + 1;
}

int bb2(int dist, int ini)
{
	int meio, fim = n;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (pos[meio] <= dist) ini = meio + 1;
		else fim = meio - 1;
	}

	return ini - 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> pos[i] >> range[i];
			pos[i] += SOMA;
			int e;
			if (range[i] > pos[i]) e = bb(0, i);
			else e = bb(pos[i]-range[i], i);

			if (e >= i) 
				last[i] = i;
			else
				last[i] = query(1, 1, n, e, i-1).first;
			update(1, 1, n, i, last[i], 0);
		}


		for (int i = n; i >= 1; i--)
		{
			int e = bb2(pos[i]+range[i], i);
			if (e <= i) 
				nxt[i] = i;
			else
				nxt[i] = query(1, 1, n, i+1, e).second;

			update(1, 1, n, i, nxt[i], 1);
		}

		for (int i = 1; i <= n; i++)
		{
			update(1, 1, n, i, last[i], 0);
			update(1, 1, n, i, nxt[i], 1);
		}

		for (int i = 1; i <= n; i++)
		{
			int e = last[i];
			int d = nxt[i];
//			cout << i << ' ' << last[i] << ' ' << nxt[i] << endl;
			while (true)
			{
				auto[x, y] = query(1, 1, n, e, d);
				if (x >= e && y <= d) break;
				if (x < e) e = x;
				if (y > d) d = y;

			}

			cout << d-e+1;
			if (i != n) cout << ' ';
		}

		cout << '\n';
	}
}
