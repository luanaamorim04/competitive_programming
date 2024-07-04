#include <iostream>
#include <vector>
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (1e4 + 10)
#define MAX (int) (1e5 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int> 

using namespace std;

ii st[MAX<<2], lazy[MAX<<2];
int t, q, n, arr[MAX], comp[MAXN], maior[MAXN], soma[MAXN];

void crivo(int n = MAXN)
{
	comp[1] = comp[0] = 1; 
	maior[1] = 1;
	for (int i = 2; i < n; i++)
	{
		if (comp[i]) continue;
		for (int j = i; j < n; j += i)
		{
			maior[j] = i, comp[j] = 1;
			int x = j;
			while (x%i == 0)
			{
				x /= i;
				soma[j] += i;
			}
		}
	}
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {arr[i], soma[arr[i]]};
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx].second = st[esq(idx)].second + st[dir(idx)].second;
}

void push(int idx, int i, int j)
{
	if (lazy[idx].first == 0) return;
	st[idx] = {lazy[idx].first, lazy[idx].second*(j-i+1)}; 
	if (i != j)
	{
		lazy[esq(idx)] = lazy[idx];
		lazy[dir(idx)] = lazy[idx];
	}

	lazy[idx] = {0, 0};
}

void del(int idx, int i, int j, int pos)
{
	push(idx, i, j);
//	cout << i << ' ' << j << ' ' << st[idx].second << endl;
	if (i == j)
	{
		st[idx].first /= maior[st[idx].first];
		st[idx].second = soma[st[idx].first];
		return;
	}

	int mid = (i+j)>>1;
	if (pos <= mid) del(esq(idx), i, mid, pos);
	else del(dir(idx), mid+1, j, pos);
	push(dir(idx), mid+1, j);
	push(esq(idx), i, mid);
	st[idx].second = st[esq(idx)].second + st[dir(idx)].second;
//	cout << i << ' ' << j << ' ' << st[idx].second << endl;
}

void update(int idx, int i, int j, int l, int r, int val)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = {val, soma[val]};
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);
	st[idx].second = st[esq(idx)].second + st[dir(idx)].second;
}

ii query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i >= l && j <= r) 
		return st[idx];
	if (i > r || j < l) return {0, 0};
	int mid = (i+j)>>1;
	ii x = query(esq(idx), i, mid, l, r);
	ii y = query(dir(idx), mid+1, j, l, r);
	return {x.first+y.first, x.second+y.second};
}

int32_t main()
{
	cin >> n;
	crivo();
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(1, 1, n);
	cin >> q;
	while (q--)
	{
		cin >> t;
		if (t == 1) 
		{
			int idx;
			cin >> idx;
			del(1, 1, n, idx);
		}
		else if (t == 2)
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r).second << endl;
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}

	}
}
