#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define int long long
#define MAXN (int) (2e5 + 5)
#define all(x) x.begin(), x.end()

using namespace std;

int n, k, grau[MAXN], qtd, vis[MAXN], u, flag[MAXN], ciclo[MAXN];
vector<int> grafo[MAXN], ord;
queue<int> fila;

void dfs(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) dfs(v);
	ord.push_back(u);
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> u;
			grafo[i].push_back(u);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);

	reverse(all(ord));
	for (int u : ord)
	{
		qtd++;
		int morre = 0;
		for (int v : grafo[u])
		{
			flag[v]++;
			if (flag[v] == qtd) morre++;
		}

		if (morre == n-qtd)
		{
			cout << qtd << ' ';
			for (int i = 1; i <= n; i++)
				if (flag[i] != qtd) cout << i << ' ';
			cout << endl;
			return 0;
		}
	}

	cout << n << ' ';
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl;
}