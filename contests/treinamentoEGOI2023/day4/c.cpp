#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#define int long long
#define all(x) x.begin(), x.end()
#define MAXN (int) (2e5 + 4)

using namespace std;

int n, k, grau[MAXN], qtd;
vector<int> grafo[MAXN];

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		while (k--)
		{
			int u;
			cin >> u;
			grau[u]++;
			grafo[i].push_back(u);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!grau[i]) fila.push(i);

	set<int> cj;
	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		cj.erase(u);
		qtd++;
		for (int v : grafo[u])
		{
			grau[u]--;
			cj.insert(v);
			if (!grau[u]) fila.push(v);
		}

		if (cj.size() >= n-qtd) 
		{

		}
	}









}