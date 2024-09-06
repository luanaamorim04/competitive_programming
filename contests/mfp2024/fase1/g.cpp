#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define ii pair<int, int> 

using namespace std;

int r[2], n;

int32_t main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		int idx, x;
		cin >> s;
		cin >> idx;
		cin >> s;
		r[idx - 1] += s[1] - '0';
	}

	cout << r[0] << " x " << r[1] << endl;
}



