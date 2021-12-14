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
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int sub[MAX], vis[MAX], resp[MAX], n, a, b;
vector<int> grafo[MAX];

int dfs(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (int v : grafo[u])
		if (v != p) sub[u] += dfs(v, u);
	return sub[u];
}

int centroid(int u, int p, int tam)
{
	for (int v : grafo[u])
		if (!vis[v] && v!=p && sub[v]>tam/2) return centroid(v, u, tam);
 	return u;
}

void build(int u, int p = 0)
{
	dfs(u);
	int k = centroid(u, 0, sub[u]);	
	resp[k] = resp[p] + 1;
	vis[k] = 1;

	for (int v : grafo[k])
		if (!vis[v]) build(v, k);
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	build(1);

	for (int i = 1; i <= n; i++)
	{
		cout << (char) (resp[i] - 1 + 'A') << endl;
	}
}
















