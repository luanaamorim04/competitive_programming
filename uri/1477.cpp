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

struct tree
{
	int a, b, c;
	tree operator + (tree q) const{
		return {a+q.a, b+q.b, c+q.c};
	}
};

tree st[1<<20];
int n, m, i, j, lazy[1<<20];
char op;

void push(int idx, int i, int j)
{
	if (!lazy[idx]) return;
	tree tmp = st[idx];
	if (lazy[idx] == 1) st[idx] = {tmp.c, tmp.a, tmp.b};
	else if (lazy[idx] == 2) st[idx] = {tmp.b, tmp.c, tmp.a};

	if (i != j)
	{
		lazy[esq(idx)] = (lazy[idx] + lazy[esq(idx)]) % 3;
		lazy[dir(idx)] = (lazy[idx] + lazy[dir(idx)]) % 3;
	}

	lazy[idx] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {1, 0, 0};
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)]+st[dir(idx)];
}

tree query(int idx, int i, int j, int l, int r)
{	
	push(idx, i, j);
	if (i > r || j < l) return {0, 0, 0};
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

void update(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = 1;
		push(idx, i, j);
		return;
	}

	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = st[esq(idx)]+st[dir(idx)];
}

int main()
{_
	while (cin >> n >> m)
	{
		build(1, 1, n);
		memset(lazy, 0, sizeof(lazy));
		while (m--)
		{
			cin >> op >> i >> j;
			if (op == 'M')
			{
				update(1, 1, n, i, j);
			}
			else
			{
				tree resp = query(1, 1, n, i, j);
				cout << resp.a << ' ' << resp.b << ' ' << resp.c << endl;
			}
		}

		cout << endl;
	}
}
