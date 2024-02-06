#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int k, t, n, arr[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int pos = 0, l = 1, r = n;
		while (pos < k)
		{
			for (int i = pos; i < n; i += k)
			{
				arr[i] = (pos&1 ? (l++) : (r--));
			}

			pos++;
		}

		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}

}
