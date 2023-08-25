//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define int long long
#define INF 1e9
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << ": " << x << endl;

using namespace std;

int n, arr[MAXN], t, m, k;

int solve(int n)
{
	return 0;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		// 3 2 1
		// 4 3 2 1 
		// 5 4 3 2 1
		// 2 1 5 4 3
		// 2 1 4 3 6 5 
		// 7 6 5 4 3 2 1

		cin >> n;
		if (n == 3)
		{
			cout << -1 << endl;
			continue;
		}

		cout << n << ' ' << n-1 << ' ';
		for (int i = 1; i < n-1; i++)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}






