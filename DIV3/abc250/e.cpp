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
#define MAX (int) (5e5 + 5)
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

int n, q, l, r, a[MAX], b[MAX], idx, resp[MAX], pode[MAX], passou[MAX];
vector<tuple<int, int, int> > queries;
map<int, int> val;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		val[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		val[b[i]] = n+i;
	}

	for (int i = 1; i <= n; i++)
	{
		b[i] = val[b[i]];
		a[i] = val[a[i]];
	}

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		queries.push_back({l, r, i});
	}

	l = r = 0;
	sort(all(queries));
	auto[a1, a2, a3] = queries[idx];
	queries.push_back({0, 0, 0});
	for (int i = 1; i <= n; i++)
	{
		pode[a[i]] = 1;
		while (!passou[a[i]] && l <= n) passou[b[++l]] = 1;
		
		while (pode[b[r+1]]) ++r;
		
		while (a1 == i)
		{
			resp[a3] = (l <= a2 && a2 <= r);
			auto[b1, b2, b3] = queries[++idx];
			a1 = b1, a2 = b2, a3 = b3;
		}
	}

	for (int i = 0; i < q; i++)
		cout << (resp[i] ? "Yes" : "No") << endl;
}












