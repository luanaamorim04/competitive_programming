// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ll long long

using namespace std;

int t, n, m, k, h, arr[MAXN], psa[MAXN], psa2[MAXN];

int solve(int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psa[i] = psa[i-1] + (arr[i] == arr[1]);
	}

	if (arr[1] == arr[n] && psa[n] >= k) return 1;

	psa2[n+1] = 0;
	for (int i = n; i >= 1; i--)
	{
		psa2[i] = psa2[i+1] + (arr[i] == arr[n]);
		if (psa[i] >= k && psa2[i] >= k) return 1;
	}

	return 0;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << (solve(n, k) ? "YES" : "NO") << endl;
	}
}