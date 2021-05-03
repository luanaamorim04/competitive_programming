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
#define lsb(x) (x & -x)
#define esq(x) ((x<<1))
#define dir(x) ((x<<1) + 1)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, q, l, r, arr[1<<20], st[1<<20][3], op;

void build(int idx, int i, int j)
{	
	if (i == j)
	{
		st[idx][0] = st[idx][1] = st[idx][2] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx][0] = st[esq(idx)][0] + st[dir(idx)][0];
	st[idx][1] = max(st[esq(idx)][1], st[dir(idx)][1]);
	st[idx][2] = min(st[esq(idx)][2], st[dir(idx)][2]);
}

int query(int idx, int i, int j, int l, int r, int tipo)
{
	if (i >= l && j <= r) return st[idx][tipo];
	if (i > r || j < l) return (tipo == 2 ? INF : 0);

	int mid = ((i+j)>>1);
	int x = query(esq(idx), i, mid, l, r, tipo);
	int y = query(dir(idx), mid+1, j, l, r, tipo);

	return (!tipo ? x+y : (tipo==1 ? max(x, y) : min(x, y)));
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j) 
	{
		st[idx][0] = st[idx][1] = st[idx][2] = val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx][0] = st[esq(idx)][0] + st[dir(idx)][0];
	st[idx][1] = max(st[esq(idx)][1], st[dir(idx)][1]);
	st[idx][2] = min(st[esq(idx)][2], st[dir(idx)][2]);
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	while (q--)
	{
		cin >> op >> l >> r;
		if (op == 1)
		{
			int mn = query(1, 1, n, l, r, 2);
			int mx = query(1, 1, n, l, r, 1);
			int sum = query(1, 1, n, l, r, 0);
			cout << sum - (mn+mx) << endl;
		}
		else
		{
			update(1, 1, n, l, r);
		}
		
	}
}














