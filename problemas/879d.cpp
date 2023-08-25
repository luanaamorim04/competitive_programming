#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

#define MAXN (int)(2e5 + 10)
#define INF (1e9 + 5)
#define ii pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, m, r[MAXN], l[MAXN], dir, esq, tam, inter;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		esq = 0;
		dir = tam = INF;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i] >> r[i];
			dir = min(r[i], dir);
			esq = max(esq, l[i]);
			tam = min(tam, r[i]-l[i]+1);
		}

		int resp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dir < l[i]) inter = 0;
			else inter = min(dir-l[i]+1, tam);
			if (esq > r[i]) inter = 0;
			else inter = min({inter, r[i]-esq+1, tam});
			resp = max(resp, r[i]-l[i]+1 - inter);
		}

		cout << resp*2 << endl;
	}
}
