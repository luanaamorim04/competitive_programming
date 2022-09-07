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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9)
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

int n, a[MAX], d[MAX], dp[MAX];
par st[MAX<<2];

int f(par st, int pos)
{
	return st.first*pos + st.second;
}

int query(int idx, int i, int j, int pos)
{
	if (i == j) return f(st[idx], i);
	int mid = (i+j)>>1;
	if (pos <= mid) return max(f(st[idx], pos), query(esq(idx), i, mid, pos));
	else return max(f(st[idx], pos), query(dir(idx), mid+1, j, pos));
}

void add(int idx, int i, int j, int m, int b)
{
	par atual = {m, b};
	if (i == j)
	{
		if (f(st[idx], i) < f(atual, i)) st[idx] = {m, b};
		return;
	}
	int mid = (i+j)>>1;
	if (f(st[idx], mid) < f(atual, mid)) swap(atual, st[idx]);
	if (f(atual, i) > f(atual, j)) add(esq(idx), i, mid, m, b);
	else add(dir(idx), mid+1, j, m, b);
}

void update(int idx, int i, int j, int m, int b, int l, int r)
{
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		add(idx, i, j, m, b);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, m, b, l, r);
	update(dir(idx), mid+1, j, m, b, l, r);
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> d[i];
		dp[i] = a[i] + query(1, 1, n, i);
		update(1, 1, n, -d[i], dp[i]+(i*d[i]), i, n);
	}

	cout << dp[n] << endl;
}
















