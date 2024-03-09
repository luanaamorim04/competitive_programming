#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

#define INF (int) (1e9  +10)
#define MAXN (int) (3e5 + 10)

using namespace std;

int t, n, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int pos = INF;
		arr[n+1] = 0;
		arr[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];

		}
		double resp = 0, soma = 0;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] < arr[i+1] && arr[i] < arr[i-1]) pos = i;
			soma += arr[i];
			if (i >= pos+1) resp = max(resp, soma/i);
		}
	
		soma = 0;
		for (int i = n; i >= 1; i--)
		{
			soma += arr[i];
			if (i <= pos-1) resp = max(resp, soma/(n-i+1));
		}

		cout << fixed << setprecision(18) << resp << endl;
	}
}
