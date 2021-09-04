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
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll st[MAX<<2];
par lazy1[MAX<<2], lazy2[MAX<<2];
int n, m, op, a, b;

void push1(int idx, int i, int j)
{	
	int mid = ((i+j)>>1);
	ll a1 = lazy1[idx].first;
	ll r = lazy1[idx].second;
	ll an = a1 + (r*(j-i));
	st[idx] += (((a1+an)*(j-i+1))>>1);
	if (i != j)
	{
		lazy1[esq(idx)].first += a1;
		lazy1[esq(idx)].second += r;
		lazy1[dir(idx)].first += (a1 + (r*(mid-i+1)));
		lazy1[dir(idx)].second += r;
	}

	lazy1[idx] = {0, 0};
}

void push2(int idx, int i, int j)
{
	int mid = ((i+j)>>1);
	ll a1 = lazy2[idx].first;
	ll r = lazy2[idx].second;
	ll an = a1 + (r*(j-i));
	st[idx] += (((a1+an)*(j-i+1))>>1);
	if (i != j)
	{
		lazy2[esq(idx)].first += (a1 + (r*(j-mid)));
		lazy2[esq(idx)].second += r;
		lazy2[dir(idx)].first += a1;
		lazy2[dir(idx)].second += r;
	}

	lazy2[idx] = {0, 0};
}

void update1(int idx, int i, int j, int l, int r, int val)
{
	push1(idx, i, j), push2(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy1[idx] = {val-i+l, -1};
		push1(idx, i, j);
		return;
	}
	int mid = ((i+j)>>1);
	update1(esq(idx), i, mid, l, r, val);
	update1(dir(idx), mid+1, j, l, r, val);
}

void update2(int idx, int i, int j, int l, int r, int val)
{
	push1(idx, i, j), push2(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy2[idx] = {val-r+j, -1};
		push2(idx, i, j);
		return;
	}
	int mid = ((i+j)>>1);
	update2(esq(idx), i, mid, l, r, val);
	update2(dir(idx), mid+1, j, l, r, val);
}

ll query(int idx, int i, int j, int pos)
{
	push2(idx, i, j), push1(idx, i, j);
	if (i == j) return st[idx];
	int mid = ((i+j)>>1);
	if (pos <= mid) return query(esq(idx), i, mid, pos);
	return query(dir(idx), mid+1, j, pos);
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b;
			update1(1, 1, n, a, min(n, a+b-1), b);
		}
		else if (op == 2)
		{
			cin >> a >> b;
			update2(1, 1, n, max(0, a-b+1), a, b);
		}
		else
		{
			cin >> a;
			cout << query(1, 1, n, a) << endl;
		}
	}
}
















