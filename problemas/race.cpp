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
#include "race.h"
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

int n, k, sub[MAX], vis[MAX], h[MAX][2], l[MAX];
vector<par> grafo[MAX];
par f[MAX*10];

int dfs(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (auto[v, w] : grafo[u])
		if (v!=p) sub[u] += dfs(v, u);
	return sub[u];
}

int centroid(int u, int p, int t)
{	
	for (auto[v, w] : grafo[u])
		if (v!=p && !vis[v] && sub[v]>t/2) return centroid(v, u, t);
	return u; 
}

int query(int u, int p, int h, int d)
{	
	if (vis[u] || d>k) return INF;
	int resp = INF;
	if (f[k-d].first) resp = f[k-d].second + h;

	for (auto[v, w] : grafo[u])
		if (v!=p) resp = min(resp, query(v, u, h+1, d+w));
	return resp;
}

void update(int u, int p, int h, int d)
{
	if (vis[u] || d>k) return;
	if (f[d].first) f[d].second = min(f[d].second, h);
	else f[d].second = h;
	f[d].first=1;

	for (auto[v, w] : grafo[u])
		if (v!=p) update(v, u, h+1, d+w);
}

void ini(int u, int p, int d)
{
	if (vis[u] || d>k) return;
	f[d] = {0, 0};

	for (auto[v, w] : grafo[u])
		if (v!=p) ini(v, u, d+w);
}

int solve(int u)
{
	dfs(u);
	int c = centroid(u, 0, sub[u]);
	vis[c] = 1;
	int resp = INF;

	f[0] = {1, 0};
	for (auto[v, w] : grafo[c])
	{
		resp = min(resp, query(v, 0, 1, w));
 		update(v, 0, 1, w);
	}	

	f[0] = {0, 0};
	for (auto[v, w] : grafo[c])
		ini(v, 0, w);

	for (auto[v, w] : grafo[c])
		if (!vis[v]) resp = min(resp, solve(v));

	return resp;
}

int best_path(int N, int K, int H[MAX][2], int L[MAX])
{
	k = K;
	for (int i = 0; i < N-1; i++)
	{
		grafo[H[i][0]+1].push_back({H[i][1]+1, L[i]});
		grafo[H[i][1]+1].push_back({H[i][0]+1, L[i]});
	}

	int resp = solve(1);
	return (resp==INF ? -1 : resp);
}

// int main()
// {
// 	cin >> n >> k;
// 	for (int i = 0; i < n-1; i++)
// 	{
// 		cin >> h[i][0] >> h[i][1] >> l[i];
// 	}

// 	cout << best_path(n, k, h, l) << endl;
// }


















