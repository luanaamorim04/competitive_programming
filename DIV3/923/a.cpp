#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int t, n, arr[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		string s;
		cin >> s;
		int l = -1, r = -1;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'B')
			{
				l = i;
				break;
			}

		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] == 'B')
			{
				r = i;
				break;
			}

		if (l == -1)
		{
			cout << 0 << endl;
			continue;
		}

		cout << r-l+1 << endl;
	}
}
