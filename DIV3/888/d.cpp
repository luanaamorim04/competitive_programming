#include <bits/stdc++.h>
//#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

int t, n, m, k, h, arr[MAXN], freq[MAXN], psa2[MAXN];

int solve(int n)
{
	vector<int> sexo;
	freq[0] = freq[n] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		freq[i] = 0;
	}

	sort(arr+1, arr+n);
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[i-1] > n || freq[arr[i] - arr[i-1]]) sexo.push_back(arr[i] - arr[i-1]);
		if (arr[i] - arr[i-1] <= n) freq[arr[i] - arr[i-1]]++;
	}

	if (freq[0]) return 0;
	if (sexo.size() > 1) return 0;
	if (sexo.size() == 0) 
	{
		return 1;
	}

	int a = -1, b = -1;
	for (int i = 1; i <= n; i++)
	{
		if (freq[i] == 0)
		{		
			if (a == -1) a = i;
			else b = i;
		}	
	}

	return sexo[0] == a+b;
	return 1;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << (solve(n) ? "YES" : "NO") << endl;
	}
}