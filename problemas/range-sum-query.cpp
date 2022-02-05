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

vector<ll> st;
vector<int> esq, dir;
ll n, m, p = 91, q = 47, a, b, tmp;
char op;

int cria()
{
	st.push_back(0);
	esq.push_back(0);
	dir.push_back(0);
	return sz(st)-1;
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i==j)
	{
		st[idx] = val;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid)
	{
		if (!esq[idx]) tmp = cria(), esq[idx] = tmp;
		update(esq[idx], i, mid, pos, val);
	}
	else
	{
		if (!dir[idx]) tmp = cria(), dir[idx] = tmp;
		update(dir[idx], mid+1, j, pos, val);	
	}

	st[idx] = st[esq[idx]]+st[dir[idx]];
}

ll query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l || !idx) return 0;
	if (i >= l && j <= r) return st[idx];

	int mid = (i+j)>>1;
	ll x = query(esq[idx], i, mid, l, r);
	ll y = query(dir[idx], mid+1, j, l, r);
	return x+y;
}

int main()
{_
	cin >> n >> m;
	cria();
	cria();
	while (m--)
	{
		cin >> op >> a >> b;
		if (op == '!') update(1, 1, n, ((a+p)%n) + 1, (b+q)%MOD);
		else
		{
			int l = ((a+p)%n) + 1;
			int r = ((b+q)%n) + 1;
			if (l>r) swap(l, r);
			ll resp = query(1, 1, n, l, r);
			p = ((p*31) + resp) % MOD;
			q = ((q*29) + resp) % MOD;
			cout << resp << endl;
		} 
	}
}








