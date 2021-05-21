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
#define ll long long
#define MAXL 21
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

int up[MAX][MAXL], tin[MAX], psa[MAX], t, n, m, a, b, tout[MAX];
vector<int> grafo[MAX];

void dfs(int u, int p)
{
	tin[u] = ++t;
	up[u][0] = p;
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];

	for (int v : grafo[u])
		if (v != p) dfs(v, u);

	tout[u] = ++t;
}

int is_anc(int u, int v)
{
	return ((tin[u] <= tin[v]) && (tout[v] <= tout[u]));
}

int LCA(int u, int v)
{
	if (is_anc(u, v)) return u;
	if (is_anc(v, u)) return v;

	for (int i = MAXL - 1; i >= 0; i--)
		if (!is_anc(up[v][i], u) && up[v][i]) v = up[v][i];
	
	return up[v][0];
}

void dfs1(int u, int p)
{
	for (int v : grafo[u])
	{
		if (v == p) continue;
		dfs1(v, u);
		psa[u] += psa[v];
	}
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1, 0);

	while (m--)
	{
		cin >> a >> b;
		int c = LCA(a, b);
		psa[a]++, psa[b]++, psa[c]--, psa[up[c][0]]--;
	}

	dfs1(1, 0);

	for (int i = 1; i <= n; i++)
		cout << psa[i] << ' ';
	cout << endl;
}














