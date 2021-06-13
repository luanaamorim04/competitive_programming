#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <bitset>
#include <stack>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, resp, vis[MAX];
vector<int> g[MAX], grafo[MAX], grafo2[MAX];
stack<int> pilha;
vector<par> arr;
map<par, int> passou;

void build(int u, int p = 0)
{
	vis[u] = 1;
	for (int v : g[u])
	{
		if (passou.find({max(v, u), min(v, u)}) != passou.end()) continue;
		passou[{max(v, u), min(v, u)}] = 1;

		grafo[u].push_back(v), grafo2[v].push_back(u);
		arr.push_back({u, v});

		if (!vis[v]) build(v, u);
	}
}

void dfs(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) dfs(v);
	pilha.push(u);
}

void scc(int u)
{
	vis[u] = 1;
	for (int v : grafo2[u])
		if (!vis[v]) scc(v);
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) build(i);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

	memset(vis, 0, sizeof vis);
	while (!pilha.empty())
	{
		int u = pilha.top(); pilha.pop();
		if (!vis[u]) ++resp, scc(u);
	}

	if (resp > 1)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	} 

	for (auto[a, b] : arr) cout << a << ' ' << b << endl;
	return 0;
}













