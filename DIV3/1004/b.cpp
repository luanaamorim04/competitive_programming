//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, arr[MAXN], freq[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			freq[arr[i]]++;
		}
		int ok = 1;
		for (int i = 1; i <= n; i++)
		{
			if (freq[i] == 1) 
			{
				ok = 0;
				break;
			}

			if (freq[i]) freq[i+1] += freq[i] - 2;
			freq[i] = 2;
		}

		for (int i = 1; i <= n; i++)
		{
			ok &= (freq[i]%2 == 0);
			freq[i] = 0;
		}	

		cout << (ok ? "YES" : "NO") << endl;
	}
}
