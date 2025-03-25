#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n;

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		int f[] = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0, 0};
		cin >> n;
		int resp = n;
		for (int i = 0; i < n; i++)
		{
			int d;
			cin >> d;
			f[d]--;
			int ok = 1;
			for (int j = 0; j <= 9; j++)
				ok &= (f[j] <= 0);
			if (ok) resp = min(resp, i);
		}
		cout << (resp == n ? 0 : resp+1) << endl;
	}
}
