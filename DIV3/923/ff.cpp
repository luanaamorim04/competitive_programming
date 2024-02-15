#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define INF (int) (1e9)
#define MAXN (int) (3e5 + 10)
#define all(x) x.begin(), x.end()
#define MAXL 22
#define _ ios_base::sync_with_stdio(false); cin->tie(0);
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define min(a, b) (a<b?a:b)

using namespace std;

int t, n, pai[MAXN], tin[MAXN], menorr[MAXN], tout[MAXN], menor[MAXN][MAXL], up[MAXN][MAXL], teste, m, a, b, c, dad[MAXN];
vector<ii> grafo[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b, int c, vector<iii> &arr2)
{
	int A = find(a), B = find(b);
	if (A == B) 
	{
		arr2.push_back({c, a, b});
		return;
	}
	grafo[a].push_back({b, c});
	grafo[b].push_back({a, c});
	pai[A] = B;
	menorr[B] = min(menorr[B], c);
}

void dfs(int u, int p, int w)
{
	up[u][0] = p;
	menor[u][0] = w;
	for (int i = 1; i < MAXL; i++)
	{
		up[u][i] = up[up[u][i-1]][i-1];
		menor[u][i] = min(menor[u][i], menor[up[u][i-1]][i-1]);
	}
	tin[u] = ++t;
	for (auto[v, peso] : grafo[u])
		if (v != p) dfs(v, u, peso);
	tout[u] = ++t;
}

int is_anc(int u, int v)
{
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int least(int u, int v)
{
	if (is_anc(v, u)) swap(v, u);
	int resp = INF;
	for (int i = MAXL-1; i >= 0; i--)
	{
		if (up[v][i] && !is_anc(up[v][i], u)) 
		{
			resp = min(resp, menor[v][i]);
			v = up[v][i];
		}

	}

	resp = min(resp, menor[v][0]);
	v = up[v][0];

	if (v == u) return resp;


	for (int i = MAXL-1; i >= 0; i--)
	{
		if (up[u][i] && !is_anc(up[u][i], v)) 
		{
			resp = min(resp, menor[u][i]);
			u = up[u][i];
		}

	}

	return min(resp, menor[u][0]);
}

void path(int u, int p)
{
	dad[u] = p;
	for (auto[v, w] : grafo[u])
		if (v != p) path(v, u);
}


int32_t main()
{
	cin >> teste;
	while (teste--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			grafo[i].clear();
			tin[i] = tout[i] = 0;
			dad[i] = 0;
			pai[i] = i;
			for (int j = 0; j < MAXL; j++)
				menor[i][j] = INF;
			menorr[i] = INF;
		}
		vector<iii> arr, arr2;
		t = 0;

		while (m--)
		{
			cin >> a >> b >> c;
			arr.push_back({c, a, b});
		}

		int resp = INF, ini = -1, fim = -1; 
		sort(all(arr));
		for (auto[w, u, v] : arr) join(u, v, w, arr2);

		
		for (int i = 1; i <= n; i++)
			if (!tin[i]) dfs(i, 0, INF);

		for (auto[w, u, v] : arr2)
		{
			if (resp > min(w, least(u, v))) 
			{

				resp = min(w, least(u, v));
				ini = u, fim = v;
			}
		}

		path(ini, 0);
		int u = fim;
		vector<int> caminho;
		while (u)
		{
			caminho.push_back(u);
			u = dad[u];
		}

		cout << resp << ' ' << caminho.size() << endl;
		for (auto x : caminho)
			cout << x << ' ';
		cout << endl;
		
	}
}

