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
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll dist[MAX];
ll n, m, a, b, c, tam[MAX], k, q, comp[MAX], vis[MAX];
vector<par> grafo[MAX], d2[MAX];
stack<int> pilha;
map<par, int> mapa;

void dfs(int u, int p = 0)
{
	vis[u] = 1;
	for (auto[v, w] : grafo[u])
	{
		if (mapa.find({v, u}) == mapa.end() && mapa.find({u, v}) == mapa.end()) d2[v].push_back({u, w});
		mapa[{u, v}] = 1;
		if (!vis[v]) dfs(v, u);
	}

	pilha.push(u);
}

void scc(int u)
{
	vis[u] = 1;
	comp[u] = k;
	for (auto[v, w] : d2[u])
	{
		if (!vis[v]) scc(v);
		if (comp[v] == k) tam[k] += w;
	}

	vis[u] = 2;
}

void dijkstra(int o)
{
	priority_queue<par, vector<par>, greater<par> > fila;
	for (int i = 1; i <= n; i++) dist[i] = INF;

	dist[o] = 0;
	fila.push({0, o});
	while (!fila.empty())
	{
		auto[d, u] = fila.top(); fila.pop();
		if (d > dist[u]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				fila.push({dist[v], v});
			}
		}
	}
}

ll solve(int o, int t)
{
	dijkstra(o);
	ll resp = INF;
	for (int i = 1; i <= n; i++)
		if (tam[comp[i]] >= t) resp = min(resp, (2*dist[i]) + tam[comp[i]]);

	return (resp==INF?-1:resp);
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	dfs(1);
	memset(vis, 0, sizeof vis);
	while (!pilha.empty())
	{
		int u = pilha.top(); pilha.pop();
		if (!comp[u])
		{
			++k;
			scc(u);
		}
	}

	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}














