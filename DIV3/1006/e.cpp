#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, k;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> k;
		vector<ii> resp;
		int a = 0, b = 0, tot = 0;
		while (tot < 500 && k)
		{
			int q = 0;
			while ((q+1)*q <= 2*k) q++;
			tot += q;
			k -= ((q-1)*q)/2;
			for (int i = 0; i < q; i++) resp.push_back({a, b++});
			a++;
		}

		cout << resp.size() << endl;
		for (auto[a, b] : resp) cout << a << ' ' << b << endl;
	}
}
