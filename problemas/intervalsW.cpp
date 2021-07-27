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
#define INF (ll) (1e15)
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

ll n, m, a, b, c, st[MAX<<2], lazy[MAX<<2];
vector<par> f[MAX];
vector<pair<ll, par> >v;

void push(int idx, int i, int j)
{
	st[idx] += lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}

	lazy[idx] = 0;
}

ll query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return -INF;
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return max(x, y);
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
	st[idx] = max(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		v.push_back({a, {b, c}});
	}

	sort(all(v));
	int idx = 0;
	for (int i = 1; i <= n+1; i++)
	{
		for (int j = 0; j < f[i-1].size(); j++)
			update(1, 0, n, 0, f[i-1][j].first-1, -f[i-1][j].second);

		while (idx < v.size() && v[idx].first == i)
		{
			auto[l, r] = v[idx++];
			f[r.first].push_back({i, r.second});
			update(1, 0, n, 0, i-1, r.second);
		}

		update(1, 0, n, i, i, query(1, 0, n, 0, i-1));
	}

	cout << query(1, 0, n, 0, n) << endl;
}















