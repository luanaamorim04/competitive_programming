#include <iostream>
#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int t, n, arr[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int resp = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr+n);
		for (int i = 0; i < n/2; i++)
		{
			resp += (arr[n-i-1] - arr[i]);
			// cout << i << endl;
		}

		cout << resp << endl;
	}
}