#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAX (int) (2e5 + 4)

using namespace std;

int t, n, arr[200], a, b, num[MAX], r;
string s;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		memset(arr, 0, sizeof arr);
		num[arr[0]] = -1;
		r = 0;
		for (int i = 1; i < s.size(); i++)
		{
			r |= (num[arr[i]] == num[arr[i-1]]);
			num[arr[i]] = -1*num[arr[i-1]];
		}

		cout << (~r ? "YES" : "NO") << endl;
	}
	return 0;
}