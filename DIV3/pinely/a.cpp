#include <iostream>
//#include <bits/stdc++.h>
#include <vector> 
#include <queue> 
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int t, n, arr[MAXN], resp;
const int INF = ((1LL<<30) - 1);

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ok = 0;
		vector<int> resp;
		for (int i = 1; i < n; i++) cin >> arr[i];

		if (n == 2) 
		{
			cout << INF << ' ' << arr[1] << endl;
			continue;
		}

		int last = INF^(arr[2]^(arr[2]&arr[1]));
		resp.push_back(last);
		for (int i = 2; i < n+1; i++) 
		{
			if (i&1) last = INF^(arr[i-2]^(arr[i-1]&arr[i-2]));
			else last = (arr[i]|arr[i-1]);
			resp.push_back(last);
		}

		for (int i = 1; i < resp.size(); i++)
			if ((resp[i]&resp[i-1]) != arr[i]) ok = 1;


		if (ok)
		{
			cout << -1 << endl;
			continue;
		}

		for (auto x : resp) cout << x << ' ';
	   cout << endl;	
	}

}
