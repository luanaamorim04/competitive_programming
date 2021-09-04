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

struct baum
{
	ll resp;
	vector<par> pref, suff;
};

baum st[MAX<<2];
ll n, L, R, arr[MAX];

ll qnt(ll x)
{
	return max(0LL, min(R-x+1, R-L+1));
}

baum join(baum &esq, baum &dir)
{
	if (esq.resp == -1) return dir;
	if (dir.resp == -1) return esq;
	baum ans;
	ans.resp = dir.resp + esq.resp;

	//pref
	ans.pref = esq.pref;
	for (int i = 0; i < sz(dir.pref); i++)
	{
		auto[a, b] = ans.pref[sz(ans.pref) - 1];
		auto[c, d] = dir.pref[i];
		if (gcd(a, c) == a)
		{
			ans.pref.pop_back();
			ans.pref.push_back({a, d+b});
		}
		else
		{
			ans.pref.push_back({gcd(a, c), d});
		}
	}

	//suff
	ans.suff = dir.suff;
	for (int i = 0; i < sz(esq.suff); i++)
	{
		auto[a, b] = ans.suff[sz(ans.suff) - 1];
		auto[c, d] = esq.suff[i];
		if (gcd(a, c) == a)
		{
			ans.suff.pop_back();
			ans.suff.push_back({a, d+b});
		}
		else
		{
			ans.suff.push_back({gcd(a, c), d});
		}
	}

	//resp
	for (auto[i, a] : dir.pref)
		for (auto[j, b] : esq.suff)
			ans.resp += (qnt(gcd(i, j))*a*b);

	return ans;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		vector<par> v;
		v.push_back({arr[i], 1});
		st[idx] = {qnt(arr[i]), v, v};
		return;
	}
	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(1, 1, n);
	cout << st[1].resp << endl;
}

















