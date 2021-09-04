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
#include <numeric>
#define ll long long
#define INF (1e9)
#define MAX (int) (1e5 + 5)
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

struct baum
{
	ll resp;
	vector<par> pref, suff;
};

baum st[MAX<<2];
ll n, m, a, b, op, arr[MAX];

baum join(baum &esq, baum &dir)
{
	baum ans;
	if (esq.resp == -1) return dir;
	if (dir.resp == -1) return esq; 
	ans.resp = esq.resp + dir.resp;
	
	// pref
	ans.pref = esq.pref;
	for (int i = 0; i < dir.pref.size(); i++)
	{
		auto[a, b] = ans.pref[ans.pref.size() - 1];
		auto[c, d] = dir.pref[i];
		if (gcd(a, c) == a)
		{
			ans.pref.pop_back();
			ans.pref.push_back({a, b+d});
		}
		else
		{
			ans.pref.push_back({gcd(a, c), d});
		}
	}

	//suff
	ans.suff = dir.suff;
	for (int i = 0; i < esq.suff.size(); i++)
	{
		auto[a, b] = ans.suff[ans.suff.size() - 1];
		auto[c, d] = esq.suff[i];
		if (gcd(a, c) == a)
		{
			ans.suff.pop_back();
			ans.suff.push_back({a, b+d});
		}
		else
		{
			ans.suff.push_back({gcd(a, c), d});
		}
	}

	//resp
	for (int i = 0; i < dir.pref.size(); i++)
	{
		for (int j = 0; j < esq.suff.size(); j++)
		{
			auto[a, b] = dir.pref[i];
			auto[c, d] = esq.suff[j];
			ans.resp += ((gcd(a, c) != 1)*b*d);
		}
	}

	return ans;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		vector<par> v;
		v.push_back({arr[i], 1});
		st[idx] = {arr[i] != 1, v, v};
		return;
	}
	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		vector<par> v;
		v.push_back({val, 1});
		st[idx] = {val != 1, v, v};
		return;
	}
	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

baum query(int idx, int i, int j, int l, int r)
{
	vector<par> v;
	if (i > r || j < l) return {-1, v, v};
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	baum x = query(esq(idx), i, mid, l, r);
	baum y = query(dir(idx), mid+1, j, l, r);
	return join(x, y);
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(1, 1, n);

	while (m--)
	{
		cin >> op >> a >> b;
		if (op == 1) update(1, 1, n, a, b);
		else cout << query(1, 1, n, a, b).resp << endl;
	}
}






