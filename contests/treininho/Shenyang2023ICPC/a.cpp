#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define MAXN (int) (4e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define INF (int) (1e9)
#define MOD (int) (1e9 + 7)
#define int long long
#define par pair<int, int> 
#define all(x) x.begin(), x.end()

using namespace std;

int arr[MAXN], quant[MAXN<<2], aaa, st[MAXN<<2], n, m, a, b, soma;
vector<par> q;
vector<int> val;
map<int, int> comp;

void update(int idx, int i, int j, int pos, int val, int f)
{
	if (i == j) 
	{
		st[idx] += val;
		quant[idx] += f;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val, f);
	else update(dir(idx), mid+1, j, pos, val, f);
	st[idx] = (st[esq(idx)]+st[dir(idx)]);
	quant[idx] = quant[esq(idx)]+quant[dir(idx)];
}

int query(int idx, int i, int j, int soma)
{
	if (i == j)
	{
		int val = st[idx]/quant[idx];
		int q = (st[idx]-soma+val-1)/val;

		if (st[idx] > soma) aaa = q;
		return i;
	}
	int mid = (i+j)>>1;
	if (st[esq(idx)] > soma) return query(esq(idx), i, mid, soma);
	return query(dir(idx), mid+1, j, soma-st[esq(idx)]);
}

int qquery(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return quant[idx];
	int mid = (i+j)>>1;
	int x = qquery(esq(idx), i, mid, l, r);
	int y = qquery(dir(idx), mid+1, j, l, r);
	return x+y;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		val.push_back(arr[i]);
	}

	while (m--)
	{
		cin >> a >> b;
		q.push_back({a, b});
		val.push_back(b);
	}

	sort(all(val));
	for (int i = 0; i < val.size(); i++)
		comp[val[i]] = i+1;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] > 0) update(1, 1, val.size()+1, comp[arr[i]], arr[i], 1);
		else soma += arr[i];
	}

	for (auto[x, v] : q)
	{
	   	if (arr[x] <= 0) soma -= arr[x];	
		else update(1, 1, val.size()+1, comp[arr[x]], -arr[x], -1);

		if (v <= 0) soma += v;
		else update(1, 1, val.size()+1, comp[v], v, 1);

		arr[x] = v;
		int pref =  query(1, 1, val.size()+1, -soma);
		cout << -aaa + 1 + qquery(1, 1, val.size()+1, 1, pref) << endl;
		aaa = 0;
	}
}
