#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)
#define par tuple<int, int, int>

using namespace std;

vector<int> grafo[MAXN];
int a, b, n, m, arr[MAXN], tam[MAXN], pai[MAXN], vis[MAXN], flag[MAXN];
vector<par> resp;

int dfs(int u, int p)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) dfs(v, u);
	
	vector<int> kids;
	for (int v : grafo[u])
		if (v != p && !flag[v]) kids.push_back(v);

	for (int i = (kids.size()&1) + 1; i < kids.size(); i += 2)
	{
		flag[kids[i]] = flag[kids[i-1]] = 1;
		resp.push_back({kids[i-1], kids[i], u});
	}

	if (kids.size()&1)
	{
		flag[u] = 1;
		flag[kids[0]] = 1;
		resp.push_back({u, kids[0], -1});
	}

//	cout << ": " << u << ' ' << kids.size() << endl; 

	return 0;
}

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int A, int B)
{
	int a = find(A), b = find(B);
	if (a == b) return;
	grafo[A].push_back(B);
	grafo[B].push_back(A);
	tam[a] += tam[b];
	pai[b] = pai[a];
}

int32_t main()
{
	cin >> n >> m;	
	for (int i = 0; i < 2*n; i++)
		pai[i] = i, tam[i] = 1;
	while (m--)
	{
		cin >> a >> b;
		join(a, b);
	}	
	

	for (int i = 0; i < 2*n; i++)
	{
		if (!vis[i])
		{
			if (tam[find(i)]&1)
			{
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}

			dfs(i, -1);
		}
	}

	cout << "POSSIBLE" << endl;
	for (auto[a, b, c] : resp)	
		cout << a << ' ' << b << ' ' << c << endl;
}
