#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define SETAR 0
#define SOMA 1
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll st[1<<20], n, m, arr[1<<20], a, b, c, op, tempo, lazy[1<<20][2];

void push(int idx, ll i, ll j)
{
	if (lazy[idx][SETAR]) st[idx] = ((j-i+1)*lazy[idx][SETAR]);
	if (lazy[idx][SOMA] == -1)
	{
		if (i != j) lazy[esq(idx)][SOMA] = lazy[dir(idx)][SOMA] = -1;
	}
	else if (lazy[idx][SOMA])
	{
		st[idx] += ((j-i+1)*lazy[idx][SOMA]);
		if (i != j)
		{
			if (lazy[esq(idx)][SOMA] == -1) lazy[esq(idx)][SETAR] += lazy[idx][SOMA];
			else lazy[esq(idx)][SOMA] += lazy[idx][SOMA];

			if (lazy[dir(idx)][SOMA] == -1) lazy[dir(idx)][SETAR] += lazy[idx][SOMA];
			else lazy[dir(idx)][SOMA] += lazy[idx][SOMA];
		}
	}

	if (i != j && lazy[idx][SETAR]) lazy[esq(idx)][SETAR] = lazy[dir(idx)][SETAR] = lazy[idx][SETAR];
	lazy[idx][SETAR] = lazy[idx][SOMA] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

ll query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0;

	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l ,r);
	return x+y;
}

void update(int idx, int i, int j, int l, int r, ll val, int tipo)
{
	push(idx, i, j);
	if (i >= l && j <= r)
	{
		if (tipo == SETAR)
		{
			lazy[idx][SOMA] = -1;
			lazy[idx][SETAR] = val;
		}
		else
		{
			lazy[idx][SOMA] = val;
		}
		push(idx, i, j);
		return;
	}
	if (i > r || j < l) return;

	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r, val, tipo);
	update(dir(idx), mid+1, j, l, r, val, tipo);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b >> c;
			update(1, 1, n, a, b, c, SOMA);
		}
		else if (op == 2)
		{
			cin >> a >> b >> c;
			update(1, 1, n, a, b, c, SETAR);
		}
		else
		{
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << endl;
		}
	}
}





















