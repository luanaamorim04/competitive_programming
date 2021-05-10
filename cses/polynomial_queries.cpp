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
#define RAZAO 0
#define FIRST 1
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

ll st[1<<20], lazy[1<<20][2], n, m, a, b, op, arr[1<<20];

void push(int idx, ll i, ll j)
{
	if (!lazy[idx][RAZAO]) return;
	ll n = (j-i+1); 
	ll a1 = lazy[idx][FIRST];
	ll aN = (a1 + ((n-1)*lazy[idx][RAZAO]));
	st[idx] += (((a1+aN)*n)>>1);

	ll mid = ((i+j)>>1);
	if (i != j)
	{
		lazy[esq(idx)][FIRST] += lazy[idx][FIRST];
		lazy[esq(idx)][RAZAO] += lazy[idx][RAZAO];
		lazy[dir(idx)][FIRST] += (a1 + ((mid+1-i)*lazy[idx][RAZAO]));
		lazy[dir(idx)][RAZAO] += lazy[idx][RAZAO];
	}

	lazy[idx][RAZAO] = lazy[idx][FIRST] = 0LL;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

ll query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0LL;

	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}	

void update(int idx, ll i, ll j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx][RAZAO] = 1LL;
		lazy[idx][FIRST] = (i-l+1);
		push(idx, i, j);
		return;
	}

	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	while (m--)
	{
		cin >> op >> a >> b;
		if (op == 1)
			update(1, 1, n, a, b);	
		else
			cout << query(1, 1, n, a, b) << endl;
	}
}













