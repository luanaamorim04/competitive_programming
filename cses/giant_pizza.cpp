#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stack>
#include <cstring>
#include <set>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX 1<<20
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

queue<int> fila;
stack<int> pilha;
set<int> tem;
set<int> grafo[MAX], dag[MAX], scc[MAX], g2[MAX];
int n, m, a, b, comp[MAX], passou[MAX], k, grau[MAX], resp[MAX], n_pode, sinal[MAX];
char c, d;

void dfs(int u)
{
	passou[u] = 1;
	for (int v : grafo[u])
		if (!passou[v]) dfs(v);
	pilha.push(u);
}

void dfs1(int u)
{
	comp[u] = k;
	scc[k].insert(u);
	for (int v : g2[u])
	{
		if (!comp[v]) dfs1(v);
		else if (comp[v] != comp[u] && dag[comp[u]].find(comp[v]) == dag[comp[u]].end())
		{
			grau[comp[v]]++;
			dag[comp[u]].insert(comp[v]);
		}
	}
}

void top_sort()
{
	for (int i = 1; i <= k; i++)
		if (!grau[i]) fila.push(i);

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int v : dag[u])
		{
			if (!(--grau[v])) fila.push(v);
		}

		for (int v : scc[u])
		{
			if (!resp[(v > m ? v - m : v + m)]) resp[v] = 1;
		}
	}
}

int main()
{_
	cin >> n >> m;
	while (n--)
	{
		cin >> c >> a >> d >> b;
		grafo[(c == '-') ? a : a + m].insert((d == '-') ? b + m : b);
		grafo[(d == '-') ? b : b + m].insert((c == '-') ? a + m : a);
		g2[(d == '-') ? b + m : b].insert((c == '-') ? a : a + m);
		g2[(c == '-') ? a + m : a].insert((d == '-') ? b : b + m);
	}

	for (int i = 1; i <= 2*m; i++) if (!passou[i]) dfs(i);

	while (!pilha.empty())
	{
		int p = pilha.top(); pilha.pop();
		if (!comp[p]) ++k, dfs1(p);
	}

	// for (int i = 1; i <= k; i++)
	// {
	// 	cout << i << ": ";
	// 	for (int v : scc[i])
	// 	{
	// 		cout << v << ' ';
	// 	}
	// 	cout << endl;
	// }

	for (int i = 1; i <= k; i++)
	{
		for (int v : scc[i])
		{
			tem.insert(v);
			n_pode |= (tem.find(v + m) != tem.end() || tem.find(v - m) != tem.end());
		}	
		tem.clear();
	}

	if (n_pode)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	top_sort();

	for (int i = 1; i <= m; i++)
		cout << (resp[i] ? '+' : '-') << ' ';
	cout << endl;
}








