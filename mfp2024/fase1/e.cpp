#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#define INF 1e18
#define MAXN (int) (1e5 + 10)
#define ii pair<int, int> 

using namespace std;

int a, b, comp[MAXN], n, q, d, k, arr[MAXN];
map<ii, int> mapa;
vector<tuple<int, int, int> > v;
vector<int> grafo[MAXN];

void dfs(int u, int p)
{
	comp[u] = comp[p];
	for (int v : grafo[u])
		if (!comp[v]) dfs(v, u);
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q >> d;

	for (int i = 0; i < n; i++)
	{
		ii p;
		cin >> p.first >> p.second;
		mapa[p] = i+1;
		v.push_back({i+1, p.first, p.second});
	}

	for (auto [a, x, y] : v)
	{
		for (int i = x-d; i <= x+d; i++)
		{
			for (int j = y-d; j <= y+d; j++)
			{
				if ((i-x)*(i-x) + (j-y)*(j-y) > d*d) continue;
				if (mapa.find({i, j}) == mapa.end()) continue;

				int b = mapa[{i, j}];
				grafo[a].push_back(b);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!comp[i]) comp[i] = ++k, dfs(i, i);
	}

	while (q--)
	{
		cin >> a >> b;
		cout << (comp[a] == comp[b] ? "S" : "N") << endl;
	}


}





