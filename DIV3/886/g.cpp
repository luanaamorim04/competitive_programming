#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)
#define ii pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, a, b, resp;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		resp = 0;
		vector<ii> v;
		map<int, int> soma, menos, l, c;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			v.push_back({a, b});
			l[a]++;
			c[b]++;
		}

		sort(all(v));
		for (auto[x, y] : v)
		{
			resp += soma[x+y];
			resp += menos[x-y];
			soma[x+y]++;
			menos[x-y]++;
		}

		resp *= 2;

		for (auto[x, y] : l)
			resp += y*(y-1);
		for (auto[x, y] : c)
			resp += y*(y-1);

		cout << resp << endl;
	}
}



