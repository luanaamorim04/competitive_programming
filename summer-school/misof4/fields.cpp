#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAXN 310
#define par tuple<int, int, int>
#define int long long
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
#define all(x) x.begin(), x.end()

using namespace std;

int n, resp, vis[MAXN], arr[MAXN], pai[MAXN], val, peso[MAXN];
vector<par> arestas;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	pai[A] = B;
	peso[B] = min(peso[B], peso[A]);
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> peso[i];
		pai[i] = i;	
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> val;
			arestas.push_back({val, i, j});
		}
	}

	sort(all(arestas));

	for (auto[w, u, v] : arestas)
	{
		if (max(peso[find(u)], peso[find(v)]) < w) continue;
		if (find(u) == find(v)) continue;
		join(u, v);
		resp += w;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[find(i)]) resp += peso[find(i)];
		vis[find(i)] = 1;
	}

	cout << resp << endl;
}
