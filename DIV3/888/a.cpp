// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ll long long

using namespace std;

int t, n, m, k, h, arr[MAXN];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> h;
		int resp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (abs(h-arr[i]) != 0 && abs(h-arr[i])%k == 0 && abs(h-arr[i])/k < m) resp++;
			// cout << resp << endl;
		}
		cout << resp << endl;
	}
}