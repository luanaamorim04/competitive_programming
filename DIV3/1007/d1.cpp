#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, k;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i) arr[i] ^= arr[i-1];
		}

		for (int i = n; i < 2*n; i++)
		{
			arr[i] = arr[i/2];
		}

		if (k < 2*n) 
		{
			cout << arr[i] << endl;
			continue;
		}

		int x = k, base = 2;
		while (x > base)
		{
			x -= base*n;
			base = (base*2);
		}

		int idx = 0;
		while (idx*base <= x)
		{
			resp = arr[idx];
			idx++;
		}
		cout << resp << endl;
	}
}
