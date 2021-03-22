#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stack>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 1<<17
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

stack<int> pilha;
vector<int> grafo1[MAX], grafo2[MAX], dag[MAX];
int n, m, a, b, coins[MAX], passou[MAX], comp[MAX], t;
ll peso[MAX], memo[MAX], resp;

void dfs1(int u)
{
	passou[u] = 1;
	for (int i = 0; i < grafo1[u].size(); i++)
	{
		int v = grafo1[u][i];
		if (!passou[v]) dfs1(v);
	}
	pilha.push(u);
}

void dfs2(int u)
{
	comp[u] = t;
	for (int i = 0; i < grafo2[u].size(); i++)
	{
		int v = grafo2[u][i];
		if (!comp[v]) dfs2(v);
		else if (comp[v] != comp[u]) dag[comp[u]].push_back(comp[v]);
	}
}

ll f(int u)
{
	if (~memo[u]) return memo[u];
	ll ans = 0;
	for (int i = 0; i < dag[u].size(); i++)
	{
		int v = dag[u][i];
		ans = max(ans, f(v) + peso[v]);
	}
	return memo[u] = ans;
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> coins[i];

	while (m--)
	{
		cin >> a >> b;
		grafo1[a].push_back(b);
		grafo2[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) if (!passou[i]) dfs1(i);

	while (!pilha.empty())
	{
		int k = pilha.top(); pilha.pop();
		if (!comp[k]) ++t, dfs2(k);
		peso[comp[k]] += coins[k];
	}

	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= n; i++) resp = max(resp, f(i) + peso[i]);

	cout << resp << endl;
}
