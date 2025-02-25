#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, k, p;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			if (((n-1)&i) == i) cout << k << ' ';
			else cout << 0 << ' ';
		}
		cout << endl;

		//for (int i = 25; i >= 0; i--)
		//{
		//	if ((1<<i) <= n) 
		//	{
		//		p = (1<<i);
		//		break;
		//	}
		//}

		//for (int i = 0; i < n-p; i++)
		//{
		//	if (n&1) cout << ((i&1) ? 0 : k) << ' ';
		//	else cout << k << ' ';
		//}

		//for (int i = n-p; i < n-(n-p); i++)
		//	cout << (n==p ? k : 0) << ' ';

		//for (int i = n-(n-p); i < n; i++)
		//{
		//	if (n&1) cout << ((i&1) ? 0 : k) << ' ';
		//	else cout << k << ' ';
		//}
		//cout << endl;
	}
}
