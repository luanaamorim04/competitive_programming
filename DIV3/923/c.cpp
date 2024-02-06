#include <iostream>
#include <set>
#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long

using namespace std;

int freq[(int)(1e6 + 10)], t, n, m, k, a[MAXN], b[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		set<int> s;
		cin >> n >> m >> k;
		int resp = 0, resp2 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] <= k) s.insert(a[i]);
			freq[a[i]]++;
		}

		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
			if (b[i] <= k) s.insert(b[i]);
			if (freq[b[i]] == 0 && b[i] <= k) freq[b[i]] = 1, resp++;
		}
		for (int i = 0; i < n; i++)
			freq[a[i]] = 0;

		for (int i = 0; i < m; i++)
			freq[b[i]]++;

		for (int i = 0; i < n; i++)
			if (freq[a[i]] == 0 && a[i] <= k) freq[a[i]] = 1, resp2++;

		for (int i = 0; i < m; i++)
			freq[b[i]] = 0;
		for (int i = 0; i < n; i++)
			freq[a[i]] = 0;

		if (resp > (k/2) || resp2 > (k/2) || s.size() != k) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
