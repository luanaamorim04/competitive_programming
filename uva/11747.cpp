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

int n, m, pai[MAX];
vector<ll> resp;
vector<tuple<ll, int, int> > arr;
ll a, b, c, t;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int main()
{_
	while (cin >> n >> m && n)
	{
		for (int i = 0; i < n; i++) pai[i] = i;
		arr.clear();
		resp.clear();
		while (m--)
		{
			cin >> a >> b >> c;
			arr.push_back({c, a, b});
		}

		sort(all(arr));

		for (auto[c, a, b] : arr)
		{
			a = find(a), b = find(b);
			if (a == b) resp.push_back(c);
			else pai[a] = b;
		}

		sort(all(resp));

		if (!resp.size()) cout << "forest";
		t = 0;
		for (ll x : resp) 
		{
			if (t) cout << ' ';
			t = 1;
			cout << x;
		}
		cout << endl;
	}
}















