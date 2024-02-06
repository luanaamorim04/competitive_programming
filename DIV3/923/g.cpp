#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define max(a, b) (a>b?a:b)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int pos[MAXN], t, n, arr[MAXN], freq[200];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int resp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			pos[i] = max(i-arr[i]+1, 1);
		}

		for (int i = n-1; i >= 1; i--)
			pos[i] = min(pos[i], pos[i+1]);

		int idx = 1;
		while (idx <= n)
		{
			int ini = idx, meio, fim = n;
			while (ini <= fim)
			{
				meio = (ini+fim)/2;
				if (pos[meio] <= idx) ini = meio + 1;
				else fim = meio - 1;
			}

			idx = (ini-1)+arr[ini-1];
			resp++;
		}

		cout << resp << endl;

	}
}
