#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int t, n, arr[MAXN], freq[200];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		for (char c = 'a'; c <= 'z'; c++) freq[c] = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			for (char c = 'a'; c <= 'z'; c++)
				if (arr[i] == freq[c])
				{
					cout << c;
					freq[c]++;
					break;
				}
		}
		cout << endl;
	}
}
