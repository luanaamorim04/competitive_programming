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

ll n, h[MAX], a[MAX], ft[MAX], resp;

ll query(int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans = max(ans, ft[idx]);
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, ll val)
{
	while (idx <= n)
	{
		ft[idx] = max(ft[idx], val);
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{	
		update(h[i], query(h[i]) + a[i]);
		resp = max(resp, query(h[i]));			
	}

	cout << resp << endl;
}






