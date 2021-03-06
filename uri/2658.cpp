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
#define MAX (int) (4e5 + 5)
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
	int freq[9];

	int resp()
	{
		int ans = 8;
		for (int i = 8; i >= 0; i--)
			if (freq[ans] < freq[i]) ans = i;
		return ans;
	}
};

tree st[MAX];
int lazy[MAX], n, m, a, b, tmp[9];

void push(int idx, int i, int j)
{
	if (!lazy[idx]) return;

	for (int i = 0; i <= 8; i++)
	{
		tmp[i] = st[idx].freq[i];
		st[idx].freq[i] = 0;
	}

	for (int i = 0; i <= 8; i++)
		st[idx].freq[((i+lazy[idx])%9)] += tmp[i];


	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}

	lazy[idx] = 0;
}	

tree combine(tree esq, tree dir)
{
	tree ans;
	for (int i = 0; i < 9; i++)
		ans.freq[i] = esq.freq[i] + dir.freq[i];
	return ans;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {{0, 1, 0, 0, 0, 0, 0, 0, 0}};
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return {{0, 0, 0, 0, 0, 0, 0, 0, 0}};
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return combine(x, y);
}

void update(int idx, int i, int j, int l, int r, int val)
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
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	cin >> n >> m;
	build(1, 1, n);
 	
	while (m--)
	{
		cin >> a >> b;
		int val = query(1, 1, n, a+1, b+1).resp();
		update(1, 1, n, a+1, b+1, val);
	}

	for (int i = 1; i <= n; i++)
		cout << query(1, 1, n, i, i).resp() << endl;
}

























