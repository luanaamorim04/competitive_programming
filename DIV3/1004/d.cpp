//#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <random>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, arr[MAXN], freq[MAXN];

int32_t main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) 
		{
			cin >> arr[i];
			freq[arr[i]]++;
		}

		int resp = 0, r, r2;
		for (int i = 1; i <= n; i++)
		{
			if (freq[i] == 0)
			{
				cout << "? " << i << ' ' << (i==1?2:1) << endl;
				cin >> r;
				if (r == 0) resp = 1;
			   	else resp = 2;	
			}
		}

		if (resp) cout << (resp == 1 ? "! A" : "! B") << endl;
		else
		{
			int a = uniform_int_distribution<int>(1, n)(rng);
			int b = uniform_int_distribution<int>(1, n)(rng);
			if (a == b) a += (a == n ? -1 : 1);
			cout << "? " << a << ' ' << b << endl;
			cin >> r;
			cout << "? " << b << ' ' << a << endl;
			cin >> r2;
			if (r == r2 && r) 
			{
				cout << "! B" << endl;
			}
			else
			{
				cout << "! A" << endl;
			}
		}

		for (int i = 1; i <= n; i++) freq[arr[i]] = 0;
	}
}
