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
#define MAXL 20

using namespace std;

int n, k, a, b, vis[MAX], f[MAX], sub[MAX], maior;
vector<int> grafo[MAX];

int dfs(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (int v : grafo[u])
		if (v!=p) sub[u] += dfs(v, u);
	return sub[u];
}

int centroid(int u, int p, int t)
{
	for (int v : grafo[u])
		if (v!=p && !vis[v] && sub[v]>t/2) return centroid(v, u, t);
	return u;
}

ll query(int u, int p, int h)
{
	if (vis[u] || h>k) return 0;
	maior = max(maior, h);
	ll resp = f[k-h];
	for (int v : grafo[u])
		if (v!=p) resp += query(v, u, h+1);

	return resp;
}

void update(int u, int p, int h)
{
	if (vis[u] || h>k) return;
	f[h]++;
	for (int v : grafo[u])
		if (v!=p) update(v, u, h+1);
}

ll solve(int u)
{
	dfs(u);
	int c = centroid(u, 0, sub[u]); 
	vis[c] = 1;
	for (int i = 0; i <= maior; i++)
		f[i] = 0;

	f[0] = 1;
	ll resp = 0;
	maior = 0;
	for (int v : grafo[c])
	{
		resp += query(v, 0, 1);
		update(v, 0, 1);
	}

	for (int v : grafo[c])
		if (!vis[v]) resp += solve(v);
	
	return resp;
}

int main()
{_
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	cout << solve(1) << endl;
}















