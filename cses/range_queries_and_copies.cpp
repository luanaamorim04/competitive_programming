#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct qry
{	
	ll st, nd, rd, th;
};

ll st[1<<20], arr[1<<20], n, m, op, a, b, x, k, resp[1<<20], idx;
vector<qry> v[1<<20];
stack<pair<int, int> > pilha;

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
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0;

	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i == j)
	{
		st[idx] = val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

void f(int k)
{
	int tam = 0;
	for (auto [a, b, c, d] : v[k])
	{
		if (a == 3)
		{
			f(c);
			resp[d] = -1;
		}
		else if (a == 1)
		{
			pilha.push({b, query(1, 1, n, b, b)});
			update(1, 1, n, b, c);
			resp[d] = -1;
			tam++;
		}
		else
		{
			resp[d] = query(1, 1, n, b, c); 
		}
	}

	while (tam--)
	{
		auto [pos, val] = pilha.top(); pilha.pop();
		update(1, 1, n, pos, val);
	}
}

int main()
{_
	cin >> n >> m;
	idx = 1;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	for (int i = 1; i <= m; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> k >> a >> x;
			v[k].push_back({op, a, x, i});
		}
		else if (op == 2)
		{
			cin >> k >> a >> b;
			v[k].push_back({op, a, b, i});
		}
		else
		{
			cin >> k;
			v[k].push_back({op, k, ++idx, i});
		}
	}

	f(1);
	for (int i = 1; i <= m; i++)
		if (~resp[i]) cout << resp[i] << endl;
}


















