#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define iii tuple<int, int, int, int> 

using namespace std;

int a, b, c, n, m, s, pai[MAXN], soma, resp;
vector<iii> arr, arr2;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) pai[i] = i;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		arr.push_back({c, a, b, i});
	}

	sort(arr.begin(), arr.end());

	vector<int> ans;
	for (auto[c, a, b, i] : arr)
	{
		if (find(a) != find(b)) pai[find(a)] = find(b), resp = max(resp, c);
	}

	cout << resp << endl;
}

