#include <iostream>
//#include <bits/stdc++.h>
#include <map>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, m, arr[MAXN], resp;
map<pair<int, int>, int> pares;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> n >> x >> y;
		resp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			int a = (arr[i]%x == 0 ? 0 : x - (arr[i]%x));
			int b = (arr[i]%y == 0 ? 0 : y - (arr[i]%y));
			if (pares.find({a, b}) != pares.end())
				resp+=pares[{a, b}];

			pares[{arr[i]%x, (y - (arr[i]%y)) % y}]++;
		}

		pares.clear();

		cout << resp << endl;
	}
	return 0;
}
