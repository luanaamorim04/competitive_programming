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
#define MAX ((ll) (2e6 + 2))
#define ADD ((ll) (1e6 + 1))
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct qquery
{
	ll p1, p2, p3, p4;
};

struct tree
{
	ll menor, qnt;
};

int cmp(qquery x, qquery y)
{
	return (x.p1 < y.p1);
}

ll lazy[(int) (MAX<<2)];
tree st[(int) (MAX<<2)];

void push(int idx, int i, int j)
{
	st[idx].menor += lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}
	lazy[idx] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].menor = 0;
		st[idx].qnt = 1;
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx].qnt = st[esq(idx)].qnt + st[dir(idx)].qnt;
	st[idx].menor = 0;
}

void update(int idx, int i, int j, int l, int r, ll val)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = val;
		push(idx, i, j);
		return;
	}

	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);

	if (st[esq(idx)].menor == st[dir(idx)].menor) 
	{
		st[idx].menor = st[esq(idx)].menor;
		st[idx].qnt = st[esq(idx)].qnt + st[dir(idx)].qnt;
	}
	else if (st[esq(idx)].menor < st[dir(idx)].menor)
	{
		st[idx].menor = st[esq(idx)].menor;
		st[idx].qnt = st[esq(idx)].qnt;
	}
	else
	{
		st[idx].menor = st[dir(idx)].menor;
		st[idx].qnt = st[dir(idx)].qnt;	
	}
}

qquery q[MAX];
ll idx, resp, n;

int main()
{_	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll xa, xb, ya, yb;
		cin >> xa >> ya >> xb >> yb;
		q[idx++] = {(xa + ADD), (ya + ADD), (yb + ADD), 1};
		q[idx++] = {(xb + ADD), (ya + ADD), (yb + ADD), -1};
	}

	build(1, 1, MAX);
	q[idx].p1 = MAX;
	sort(q, q+idx, cmp);

	for (int i = 0; i < idx; i++)
	{
		auto[tempo, l, r, op] = q[i];
		update(1, 1, MAX, l, r-1, op);
		ll range = MAX-st[1].qnt;
		resp += (range*((q[i+1].p1 - tempo)));
	}

	cout << resp << endl;
}	



















