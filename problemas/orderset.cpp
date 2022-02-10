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
#define INF (ll) (1e9)
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

int n, k;
char op;
vector<int> st, esq, dir;

int cria()
{
	st.push_back(0);
	esq.push_back(0);
	dir.push_back(0);
	return sz(st)-1;
}

void update(int idx, ll i, ll j, ll pos, int val)
{
	if (i==j)
	{
		st[idx] = (val==1?1:0);
		return;
	}

	ll mid = (i+j)>>1;
	if (pos <= mid) 
	{
		if (!esq[idx]) esq[idx] = cria();
		update(esq[idx], i, mid, pos, val);
	}
	else
	{
		if (!dir[idx]) dir[idx] = cria();
		update(dir[idx], mid+1, j, pos, val);
	}

	st[idx] = st[esq[idx]] + st[dir[idx]];
}

int query1(int idx, ll i, ll j, ll k)
{
	if (!idx) return -1;
	if (i==j) return i;
	ll mid = (i+j)>>1;
	if (st[esq[idx]] >= k) return query1(esq[idx], i, mid, k);
	return query1(dir[idx], mid+1, j, k-st[esq[idx]]);
}

int query2(int idx, ll i, ll j, ll l, ll r)
{
	if (i > r || j < l || !idx) return 0;
	if (i >= l && j <= r) return st[idx];
	ll mid = (i+j)>>1;
	int x = query2(esq[idx], i, mid, l, r);
	int y = query2(dir[idx], mid+1, j, l, r);
	return x+y;
}

int main()
{_
	cin >> n;
	cria();
	cria();
	while (n--)
	{
		cin >> op >> k;
		k += INF;
		if (op=='I') update(1, 0, INF<<1, k, 1);
		else if (op == 'C') cout << query2(1, 0, INF<<1, 0, k-1) << endl;
		else if (op == 'K')
		{
			int resp = query1(1, 0, INF<<1, k-INF) - INF;
			cout << (resp == -(INF+1) ? "invalid" : to_string(resp)) << endl;
		}	 
		else update(1, 0, INF<<1, k, -1);
	}
}








