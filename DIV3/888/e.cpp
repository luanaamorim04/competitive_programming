#include <bits/stdc++.h>
//#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define int long long
#define ii pair<int, int>

using namespace std;

int t, n, m, k, resp[MAXN], dist[MAXN], ord[MAXN], pos[MAXN], memo[MAXN];
vector<int> grafo[MAXN];

int comp(int a, int b)
{
	return resp[a] < resp[b];
}

int dp(int u)
{
	int r = 0;
	if (~memo[u]) return memo[u];
	if (!grafo[u].size()) return resp[u];
	for (int v : grafo[u])
		r += dp(v);

	return memo[u] = min(resp[u], r);
}

void solve(int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		resp[i] = x; 
		ord[i] = i;
		memo[i] = -1;
		grafo[i].clear();
	}

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		resp[x] = 0;
	}

	sort(ord+1, ord+n+1, comp);

	for (int i = 1; i <= n; i++)
		pos[ord[i]] = i;

	for (int i = 1; i <= n; i++)
	{
		int k, ok = 0;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			grafo[i].push_back(x);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dp(i) << ' ';
	cout << endl;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		solve(n, k);
	}
}