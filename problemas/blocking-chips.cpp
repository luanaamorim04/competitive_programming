#include <iostream>
#include <vector>
#define MAXN (int)(2e5 + 10)

using namespace std;

int t, n, k, a, b, arr[MAXN], flag[MAXN], prof[MAXN], qtd[MAXN], ans;
vector<int> grafo[MAXN];

void dfs(int u, int p)
{
	for (int v : grafo[u])
	{
		if (v == p) continue;
		dfs(v, u);
	}

	for (int v : grafo[u])
	{
		if (v == p || flag[v]) continue;
		prof[u] = max(prof[u], prof[v] + 1);
	}

	// printf("\033[31mprof[%d]: %d\033\n", u, prof[u]);
	// printf("\033[31mqtd[%d]: %d\033\n", u, qtd[u]);
	// printf("\033[31mflag[%d]: %d\033\n", p, flag[p]);

	if (prof[u] >= qtd[u]) return;
	if (flag[p]) ans = 0;
	flag[p] = 1;
	qtd[p] = qtd[u] - 1;
}

int f(int x)
{
	for (int i = 1; i <= n; i++)
		flag[i] = qtd[i] = prof[i] = 0;
	flag[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		flag[arr[i]] = 1;
		qtd[arr[i]] = x/k;
	}

	for (int i = 1; i <= x%k; i++)
		qtd[arr[i]]++;

	ans = 1;
	dfs(1, 0);
	return ans;
}

int main()
{	
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) grafo[i].clear();

		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		cin >> k;
		for (int i = 1; i <= k; i++)
			cin >> arr[i];

		int ini = 1, meio, fim = n;
		while (ini <= fim)
		{
			meio = (ini+fim)>>1;
			if (f(meio)) ini = meio + 1;
			else fim = meio - 1;
		}

		cout << ini - 1 << endl;
	}
}