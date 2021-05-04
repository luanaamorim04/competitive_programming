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
#define SUM 0
#define PREF 1
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, q, a, b, arr[1<<20], st[1<<20][2], op;

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx][SUM] = arr[i];
		st[idx][PREF] = max(0LL, arr[i]); 
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx][SUM] = st[esq(idx)][SUM] + st[dir(idx)][SUM];
	st[idx][PREF] = max(st[esq(idx)][PREF], st[esq(idx)][SUM] + st[dir(idx)][PREF]);
}

par query(int idx, int i, int j, int l, int r)
{
	if (i >= l && j <= r) return {st[idx][PREF], st[idx][SUM]};
	if (i > r || j < l) return {0LL, 0LL};

	int mid = ((i+j)>>1);
	par x = query(esq(idx), i, mid, l, r);
	par y = query(dir(idx), mid+1, j, l, r);
	return {max(x.first, x.second + y.first), x.second + y.second};
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i == j)
	{
		st[idx][SUM] = val;
		st[idx][PREF] = max(0LL, val);
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx][SUM] = st[esq(idx)][SUM] + st[dir(idx)][SUM];
	st[idx][PREF] = max(st[esq(idx)][PREF], st[esq(idx)][SUM] + st[dir(idx)][PREF]);
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	while (q--)
	{
		cin >> op >> a >> b;
		if (op == 1)
			update(1, 1, n, a, b);
		else
			cout << query(1, 1, n, a, b).first << endl;
	}
}
