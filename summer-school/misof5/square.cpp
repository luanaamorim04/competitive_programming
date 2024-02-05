#include <iostream>
#include <bits/stdc++.h>
#include <map>
#define MAXN (int) (2e5 + 10)
#define int long long
#define INF (1e9)
#define MOD (int) (1e9 + 7)
#define all(x) x.begin(), x.end()
#define _ ios_base::sync_with_stdio(false); cin->tie(0);

using namespace std;

int n, m, a[MAXN], b[MAXN], db[MAXN], resp;
map<int, int> da;

int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < i; j++)
			da[a[i]-a[j]]++;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		for (int j = 0; j < i; j++)
			resp += da[b[i]-b[j]];
	}

	cout << resp << endl;
	return 0;
}
