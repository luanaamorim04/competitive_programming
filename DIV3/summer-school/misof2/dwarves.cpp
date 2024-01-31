#include <bits/stdc++.h> 
#define int long long
#define MAXN (int) (1e5)
#define INF (int) (1e9)

using namespace std;

int n, arr[MAXN];

int32_t main()
{
	n = 6;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	sort(arr+1, arr+1+n);
	int r1 = arr[2]-arr[1], ok = 0, c = 0;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i]-arr[i-1] != r1)
		{
			c++;
			if (arr[i]-arr[i-1] == 2*r1) ok = i;
		}
	}

	if (c == 0)
	{
		if (arr[1] - r1 > 0) cout << arr[1] - r1 << endl;
		if (r1) cout << arr[n] + r1 << endl;
		return 0;
	}

	if (c == 1 && ok)
	{
		cout << arr[ok-1]+r1 << endl;
		return 0;
	}

	int r2 = arr[3]-arr[2];
	c = 0, ok = 0;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i]-arr[i-1] != r2)
		{
			cout << arr[i-1]+r2 << endl;
			return 0;
		}
	}
}
