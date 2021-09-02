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

int n, m, a, b, pai[MAX], t;
par arr[MAX];
vector<tuple<ll, int, int> > v;

int f(int a, int b)
{
	if (!a) return b;
	if (!b) return a;
	if (a == b) return a-1;
	else if (a%2 == 0 && b%2 == 0) return 1;
	return 0;
}

int find(int x)
{	
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		ll resp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
			for (int j = 0; j < i; j++)
			{
				int x = gcd(abs(arr[i].first-arr[j].first), abs(arr[i].second-arr[j].second)) - 1;
				v.push_back({x, i, j});
			}
		}

		for (int i = 0; i < n; i++) pai[i] = i;
		sort(all(v));
		for (auto[c, a, b] : v)
		{
			a = find(a);
			b = find(b);
			if (a == b) continue;
			resp += c, pai[a] = b;
		}

		cout << resp*m << endl;
		v.clear();
	}
}












