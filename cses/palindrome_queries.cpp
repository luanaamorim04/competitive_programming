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
#define MOD (int) (1e9 + 7)
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define B 37
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int n, m, op, l, r;
ll ft1[MAX], ft2[MAX], a[MAX];
string s;
char c;
 
void update(ll (&ft)[MAX], int idx, ll val)
{
	val = (val + (100LL*MOD)) % MOD;
	while (idx <= n)
	{
		ft[idx] = (ft[idx] + val) % MOD;
		idx += lsb(idx);
	}
}
 
ll query(ll (&ft)[MAX], int idx)
{
	ll resp = 0;
	while (idx > 0)
	{
		resp = (resp + ft[idx]) % MOD;
		idx -= lsb(idx);
	}
	return resp;
}
 
int main()
{_
	cin >> n >> m >> s;
	a[0] = 1;
	for (int i = 1; i < MAX; i++)
		a[i] = (a[i-1]*B) % MOD;
 
	for (int i = 0; i < n; i++)
	{
		s[i] = (s[i] - 'a') + 1;
		update(ft1, i+1, a[n-(i+1)]*s[i]);
		update(ft2, i+1, a[i]*s[i]);
	}
 
	while (m--)
	{
		cin >> op;
		if (op&1)
		{
			cin >> l >> c;
			update(ft1, l, -a[n-l]*s[l-1]);
			update(ft2, l, -a[l-1]*s[l-1]);
			s[l-1] = (c - 'a') + 1;
			update(ft1, l, a[n-l]*s[l-1]);
			update(ft2, l, a[l-1]*s[l-1]);
		}
		else
		{
			cin >> l >> r;
			l--;
			ll p1 = (query(ft1, r) - query(ft1, l) + MOD) % MOD;
			ll p2 = (query(ft2, r) - query(ft2, l) + MOD) % MOD;
 
			if (l > n-r) p1 = (p1 * a[l-(n-r)]) % MOD;
			else p2 = (p2 * a[(n-r)-l]) % MOD;	
 
			cout << (p1 == p2 ? "YES" : "NO") << endl;
		}
	}
}	