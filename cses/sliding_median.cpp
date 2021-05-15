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

int freq[1<<20], n, k, t, cp[1<<20], arr[1<<20];
par st[1<<20];
map<int, int> val, rev;

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].second = i;
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

int query(int idx, int i, int j, int tot)
{
	if (i == j) return st[idx].second;
	int mid = ((i+j)>>1);
	if (tot + st[esq(idx)].first <= t-1) return query(dir(idx), mid+1, j, tot + st[esq(idx)].first);
	return query(esq(idx), i, mid, tot);
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx].first += val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx].first = st[esq(idx)].first + st[dir(idx)].first;
}

int main()
{_
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cp[i] = arr[i];
	}

	build(1, 1, n);

	sort(cp+1, cp+n+1);
	for (int i = 1; i <= n; i++)
	{
		if (!val.count(cp[i]))
		{
			val[cp[i]] = i;
			rev[i] = cp[i];
		}
	}

	t = ((k+1)>>1);

	for (int i = 1; i <= k; i++) update(1, 1, n, val[arr[i]], 1);
	cout << rev[query(1, 1, n, 0)] << ' ';

	for (int i = k+1; i <= n; i++)
	{
		update(1, 1, n, val[arr[i]], 1);
		update(1, 1, n, val[arr[i-k]], -1);
		cout << rev[query(1, 1, n, 0)] << ' ';
	}

	cout << endl;
}















