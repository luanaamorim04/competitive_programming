#include <iostream>
#include <vector>
#include <map> 
#include <math.h> 
#include <set>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define all(x) x.begin(), x.end()
#define INF (int) (1e9)
#define ii pair<int, int> 
#define iii tuple<int, int, int> 

using namespace std;

int m, k, t, n, f1[MAXN], f2[MAXN], arr[MAXN], brr[MAXN], a, b, c;
string s;
set<int> s1, s2;
int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		k = m - k;
		int diff = 0;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= m; i++)
		{
			cin >> brr[i];
			f1[brr[i]]++;
			f2[arr[i]]++;
		}

		for (int i = 1; i <= m; i++)
		{
			diff += (f1[brr[i]] > f2[arr[i]]);
			f1[brr[i]]--;
		}

		cout << diff << endl;

		for (int i = 1; i <= m; i++)
			f1[brr[i]]++;

		int resp = (diff <= k);
		for (int i = m+1; i <= n; i++)
		{
			if (f2[arr[i-m]] > f1[arr[i-m]]) diff--;
			else diff++;

			f2[arr[i-m]]--;


			if (f2[arr[i]] < f1[arr[i]]) diff--;

			f2[arr[i]]++;



			cout << diff << ' ';
			resp += (diff <= k);
		}

		cout << endl;
		cout << resp << endl;

		for (int i = 1; i <= m; i++)
			f1[brr[i]] = f2[brr[i]] = 0;

	}
}
