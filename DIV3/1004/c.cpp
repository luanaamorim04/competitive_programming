//#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int num = 0, resp = 10;
		for (int q = 0; q <= 10; q++)
		{
			for (int r = 0; r < 20; r++)
			{
				int x = n;
				x += r*num;
				while (x)
				{
					if (x%10 == 7) resp = min(resp, r);
					x /= 10;
				}
			}

			num*= 10;
			num += 9;
		}
		cout << resp << endl;
	}
}
