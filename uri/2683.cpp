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
#define MAX (int) (2e3 + 5)
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

ll pai[MAX], n, m, a, b, c;
vector<tuple<ll, ll, ll> > v;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

ll mst()
{
	ll resp = 0;
	for (int i = 1; i < MAX; i++) pai[i] = i;
	for (auto[c, a, b] : v)
	{
		a = find(a), b = find(b);
		if (a != b)
		{
			resp += c;
			pai[a] = b;
		}
	}
	return resp;
}

int main()
{_
	cin >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		v.push_back({c, a, b});
	}

	sort(all(v), greater<tuple<int, int, int> >());
	cout << mst() << endl;
	sort(all(v));
	cout << mst() << endl;
}
