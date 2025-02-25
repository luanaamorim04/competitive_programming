#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define MAXL (int) 20
#define iii tuple<int, int, int>
#define ii pair<int, int> 
#define int long long

using namespace std;

vector<iii> arr, orig;
int pai[MAXN], n, m, a, b, p, c, t, up[MAXN][MAXL], tin[MAXN], tout[MAXN], maior[MAXN][MAXL];
vector<ii> grafo[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b, int c)
{
	grafo[a].push_back({b, c});
	grafo[b].push_back({a, c});
	a = find(a), b = find(b);
	pai[a] = b;
}

void dfs(int u, int p, int a)
{
	up[u][0] = p;
	maior[u][0] = a;
	tin[u] = ++t;
	for (int i = 1; i < MAXL; i++)
	{
		maior[u][i] = max(maior[u][i-1], maior[up[u][i-1]][i-1]);
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for (auto[v, w] : grafo[u])
		if (v != p) dfs(v, u, w);
	   	
	tout[u] = ++t;
}

int is_anc(int u, int v)
{
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v)
{
	if (is_anc(u, v)) return u;
	if (is_anc(v, u)) return v;

	for (int i = MAXL-1; i >= 0; i--)
		if (!is_anc(up[u][i], v)) u = up[u][i];

	return up[u][0];
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) pai[i] = i;

	while (m--)
	{
		cin >> a >> b >> c;
		arr.push_back({c, a, b});
		orig.push_back({a, b, c});
	}

	sort(arr.begin(), arr.end());

	for (auto[c, a, b] : arr)
	{
		if (find(a) == find(b)) continue;
		join(a, b, c);
		p += c;
	}

	dfs(1, 0, 0);
	tout[0] = 1e9;

	for (auto[a, b, c] : orig)
	{	
		int l = LCA(a, b), resp = 0;
		if (a != l) 
		{
			for (int i = MAXL-1; i >= 0; i--) if (!is_anc(up[a][i], l)) resp = max(resp, maior[a][i]), a = up[a][i];
			resp = max(resp, maior[a][0]), a = up[a][0];
		}
		if (b != l)
		{
			for (int i = MAXL-1; i >= 0; i--) if (!is_anc(up[b][i], l)) resp = max(resp, maior[b][i]), b = up[b][i];
			resp = max(resp, maior[b][0]), b = up[b][0];
		}

		cout << p + c - resp << endl;
	}
}
