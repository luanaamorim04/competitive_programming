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
#define INF (ll) (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define LEFT 0
#define RIGHT 1
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct tree
{
	ll resp, id, tam;
};

tree st[1<<20][2];
ll arr[1<<20], n, m, k, op, a, b;

tree combine(tree esq, tree dir, int caso)
{
	tree ans;
	ans.tam = esq.tam + dir.tam;
	if (caso == RIGHT)
	{
		if (esq.resp <= dir.resp + esq.tam)
		{
			ans.resp = esq.resp;
			ans.id = esq.id;
		}
		else
		{
			ans.resp = dir.resp + esq.tam;
			ans.id = dir.id + esq.tam;
		}
	}
	else
	{
		if (dir.resp <= esq.resp + dir.tam)
		{
			ans.resp = dir.resp;
			ans.id = dir.id + esq.tam;
		}
		else
		{
			ans.resp = esq.resp + dir.tam;
			ans.id = esq.id;
		}
	}

	return ans;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx][LEFT] = st[idx][RIGHT] = {arr[i], 0, 1};
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx][LEFT] = combine(st[esq(idx)][LEFT], st[dir(idx)][LEFT], LEFT);
	st[idx][RIGHT] = combine(st[esq(idx)][RIGHT], st[dir(idx)][RIGHT], RIGHT);
}

tree query(int idx, int i, int j, int l, int r, int caso)
{
	if (i >= l && j <= r) return st[idx][caso];
	if (i > r || j < l) return {INF, 0, 0};

	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r, caso);
	tree y = query(dir(idx), mid+1, j, l, r, caso);
	return combine(x, y, caso);
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i == j)
	{
		st[idx][RIGHT] = st[idx][LEFT] = {val, 0, 1};
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update (dir(idx), mid+1, j, pos, val);
	st[idx][LEFT] = combine(st[esq(idx)][LEFT], st[dir(idx)][LEFT], LEFT);
	st[idx][RIGHT] = combine(st[esq(idx)][RIGHT], st[dir(idx)][RIGHT], RIGHT);
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
		if (op == 2)
		{
			cin >> k;
			cout << min(query(1, 1, n, k, n, RIGHT).resp, query(1, 1, n, 1, k, LEFT).resp) << endl;
		}
		else
		{
			cin >> a >> b;
			update(1, 1, n, a, b);
		}
	}
}











