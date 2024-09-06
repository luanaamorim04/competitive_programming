#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e9 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int k, n, m, t, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int ok = 1;
		map<int, int> freq;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> k;
				freq[k]++;
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> k;
				if (freq[k] == 0) ok = 0;
				freq[k]--;
			}

		cout << (ok ? "YES" : "NO") << endl;
	}

}
