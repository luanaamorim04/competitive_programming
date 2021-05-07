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
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll st[1<<20], lazy[1<<20], n, m, a, b, c, op, t;

void push(int idx, int i, int j)
{
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}
	st[idx] += ((j-i+1)*lazy[idx]);
	lazy[idx] = 0;
}

ll query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0LL;
	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

void update(int idx, int i, int j, int l, int r, ll val)
{
	push(idx, i, j);
	if (i >= l && j <= r) 
	{
		lazy[idx] += val;
		push(idx, i, j);
		return;
	}
	if (i > r || j < l) return;
	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}	

int main()
{_
	cin >> t;
	while (cin >> n >> m)
	{
		memset(lazy, 0, sizeof(lazy));
		memset(st, 0, sizeof(st));

		while (m--)
		{
			cin >> op;
			if (op)
			{
				cin >> a >> b;
				cout << query(1, 1, n, a, b) << endl;
			}
			else
			{
				cin >> a >> b >> c;
				update(1, 1, n, a, b, c);
			}
		}
	}
}
