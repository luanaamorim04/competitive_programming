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

int t, n, m, a, b, k, tam[MAX<<1], passou[MAX<<1], resp[MAX<<1], comp[MAX<<1];
vector<int> grafo[MAX<<1], grafo2[MAX<<1];
stack<int> pilha;
queue<int> fila;

void dfs(int u)
{
	comp[u] = 0;
	resp[u] = 0;
	passou[u] = 1;
	for (int v : grafo[u])
		if (!passou[v]) dfs(v);
	pilha.push(u);
}

void scc(int u)
{
	comp[u] = k;
	tam[k]++;
	for (int v : grafo2[u]) 
		if (!comp[v]) scc(v);
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(passou, 0, sizeof passou);
		while (m--)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo2[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) dfs(i);
		while (!pilha.empty())
		{
			int u = pilha.top(); pilha.pop();
			if (!comp[u]) 
			{
				++k;
				tam[k] = 0;
				scc(u);
			}
		}

		fila.push(1);
		while (!fila.empty())
		{

		}

		for (int i = 1; i <= n; i++)
			cout << comp[i] << ' ' << tam[comp[i]] << endl;
	}
}	







