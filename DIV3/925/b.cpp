#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define max(a, b) (a > b ? a : b)
#define INF (int) (1e9)
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, m, arr[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			tot += arr[i];
		}
		tot /= n;

		int soma = 0;
		for (int i = 1; i <= n; i++)
		{
			soma += max(0, arr[i] - tot);
			soma -= max(0, tot - arr[i]);
			if (soma < 0) break;
		}

		cout << (soma ? "NO" : "YES") << endl;
	}
	return 0;
}
