#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int> 

using namespace std;

ii arr[4];

int32_t main()
{
	for (int i = 0; i < 4; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr+4);

	cout << abs(arr[0].first-arr[3].first)*abs(arr[0].second-arr[3].second) << endl;
}
