// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ll long long

using namespace std;

int t, n, m, k, h, arr[MAXN];

int solve(int n)
{
	priority_queue<int, vector<int>, greater<int> > par, impar;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i]&1) impar.push(arr[i]);
		else par.push(arr[i]);
	}

	int maior = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]&1)
		{
			if (maior > impar.top()) return 0;
			maior = impar.top();
			impar.pop();
		}
		else
		{
			if (maior > par.top()) return 0;
			maior = par.top();
			par.pop();
		}
	}
	return 1;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << (solve(n) ? "YES" : "NO") << endl;
	}
}