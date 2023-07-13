#include <iostream>
#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int t, n, arr[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int resp = 0;
		while (n)
		{
			resp += n;
			n>>=1;
		}

		cout << resp << endl;
	}
}