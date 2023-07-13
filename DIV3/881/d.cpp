#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int t, n, arr[MAXN], q, folhas[MAXN], grau[MAXN], pai[MAXN], a, b;
vector<int> grafo[MAXN];

void dfs(int u, int p)
{
	for (int v : grafo[u])
	{
		if (v==p) continue;
		dfs(v, u);
		folhas[u] += folhas[v];
	}

	folhas[u] = max(folhas[u], 1LL);
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
			grau[a]++; grau[b]++;
		}

		dfs(1, 0);
		cin >> q;
		while (q--)
		{
			cin >> a >> b;
			cout << folhas[a] * folhas[b] << endl;
		}

		for (int i = 1; i <= n; i++)
		{
			folhas[i] = 0;
			grafo[i].clear();
		}


	}
}