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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll st[4*MAX], arr[MAX], n, q, op, a, b;
void build(int idx, int i, int j)
{
	if (i==j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = (st[esq(idx)] + st[dir(idx)]) % MOD;
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i==j)
	{
		st[idx] = (st[idx] + val) % MOD;
		return;
	}

	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
}

ll query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];

	int mid = (i+j)>>1;
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return (x+y) % MOD;
}

void build(int idx, int i, int j)
{
	if (i==j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = (st[esq(idx)] + st[dir(idx)]) % MOD;
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i==j)
	{
		st[idx] = (st[idx] + val) % MOD;
		return;
	}

	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
}

ll query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];

	int mid = (i+j)>>1;
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return (x+y) % MOD;
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	build(1, 1, n);
	cout << st[1] << endl;
	while (q--)
	{
		cin >> op >> a >> b;
		if (op)
		{
			cout << query(1, 1, n, a, b) << endl;
		}
		else
		{
			update(1, 1, n, a, b);
		}
	}
}











