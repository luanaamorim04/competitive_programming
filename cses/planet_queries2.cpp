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
#define MAXL 20
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

int caso, q, a, b, n, qnt, t, pai[MAX], tam[MAX], comp[MAX], ini[MAX], grau[MAX], dist[MAX], pos[MAX], tin[MAX], tout[MAX];
vector<int> filhos[MAX];

void dfs(int u)
{
	grau[u]--;
	grau[pai[u]]--;
	if (!grau[pai[u]])
		dfs(pai[u]);
}

void dfs2(int u, int d, int k)
{
	ini[u] = k;
	dist[u] = d;
	tin[u] = ++t;
	for (int v : filhos[u])
		dfs2(v, d+1, k);
	tout[u] = ++t;
}

void pre()
{
	int idx, x;
	for (int i = 1; i <= n; i++) if (!grau[i]) dfs(i);

	for (int i = 1; i <= n; i++)
	{
		if (grau[i] > 0)
		{
			idx = 0;
			pos[i] = ++idx;
			comp[i] = ++qnt;
			tam[qnt] = 1;
			x = pai[i];
			while (x != i)
			{
				tam[qnt]++;
				comp[x] = qnt;
				grau[x] = 0;
				pos[x] = ++idx;
				x = pai[x];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!comp[i]) continue;
		for (int v : filhos[i])
			if (!comp[v]) dfs2(v, 1, i);
	}
}

int is_anc(int a, int b)
{
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int solve(int a, int b)
{
	// dois ciclo
	if (comp[a] && comp[b])
	{
		if (comp[a] != comp[b]) return -1;
		return (pos[a] <= pos[b] ? pos[b]-pos[a] : tam[comp[a]]-(pos[a]-pos[b]));
	}

	// dois fora
	if (!comp[a] && !comp[b])
	{
		if (!is_anc(b, a)) return -1;
		return dist[a]-dist[b];
	}

	// um fora
	if (comp[a] || comp[ini[a]]!=comp[b]) return -1;
	return dist[a] + (pos[ini[a]] <= pos[b] ? pos[b]-pos[ini[a]] : tam[comp[b]]-(pos[ini[a]]-pos[b]));
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> pai[i];
		grau[pai[i]]++;
		filhos[pai[i]].push_back(i);
	}

	pre();
	for (caso = 1; caso <= q; caso++)
	{
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}












