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
#define INF (ll)(1e9 + 7)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, q, a, b, l, r, tmp;
vector<ll> st, esq, dir, lazy;

int cria()
{
	lazy.push_back(0);
	st.push_back(0);
	esq.push_back(0);
	dir.push_back(0);
	return sz(st) - 1;
}

void push(int idx, ll i, ll j)
{ 
	if (!idx || !lazy[idx]) return;
	st[idx] += lazy[idx];
	if (!esq[idx]) tmp = cria(), esq[idx] = tmp;
	if (!dir[idx]) tmp = cria(), dir[idx] = tmp;
	if (i != j)
	{
		lazy[esq[idx]] += lazy[idx];
		lazy[dir[idx]] += lazy[idx];
	}

	lazy[idx] = 0;
}

void update(int idx, ll i, ll j, ll l, ll r)
{
	if (i > r || j < l) return;
	if (!esq[idx]) tmp = cria(), esq[idx] = tmp;
	if (!dir[idx]) tmp = cria(), dir[idx] = tmp;
	push(idx, i, j);

	if (i >= l && j <= r)
	{
		lazy[idx]++;
		push(idx, i, j);
		return;
	}	

	ll mid = (i+j)>>1;
	update(esq[idx], i, mid, l, r);
	update(dir[idx], mid+1, j, l, r);
	st[idx] = max(st[esq[idx]], st[dir[idx]]);
}

ll query(ll idx, ll i, ll j, ll l, ll r)
{
	push(idx, i, j);
	if (i > r || j < l || !idx) return 0;
	if (i >= l && j <= r) return st[idx];
	ll mid = (i+j)>>1;
	ll x = query(esq[idx], i, mid, l, r);
	ll y = query(dir[idx], mid+1, j, l, r);
	return max(x, y);
}

int main()
{_
	cria();
	cria();
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		update(1, 1, INF, a, b);
	}

	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		if (l > r) swap(l, r);
		cout << query(1, 1, INF, l, r) << endl;
	}

	return 0;
}













