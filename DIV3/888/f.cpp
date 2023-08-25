//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define int unsigned long long

using namespace std;

int t, n, m, k;

void solve(int n, int k)
{
	vector<pair<int, int> > arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back({a, i+1});
	}

	sort(all(arr));
	int menor = 1LL<<30;
	for (int i = 1; i < n; i++)
	{
		if (menor > (arr[i].first^arr[i-1].first))
		{
			// cout << arr[i].first << ' ' << arr[i-1].first << endl;
			menor = arr[i].first^arr[i-1].first;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if ((arr[i].first^arr[i-1].first) == menor)
		{
			cout << arr[i-1].second << ' ' << arr[i].second << ' ' << (((1LL<<k) - 1)^(arr[i].first&arr[i-1].first)) << endl;
			return;
		}
	}
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		solve(n, k);
	}
}