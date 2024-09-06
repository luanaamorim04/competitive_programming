#include <iostream>
#include <stack>
#include <vector>
#define MAXN (int) (3e5 + 10)
#define ii pair<int, int> 

using namespace std;

int m, resp[MAXN], freq[MAXN][3], tam[MAXN], pai[MAXN], t, n, q, a, b, l[MAXN], r[MAXN];
string op;
vector<int> grafo[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	if (A == B) return;
	grafo[a].push_back(b);
	grafo[b].push_back(a);
	if (tam[A] < tam[B]) swap(A, B);
	pai[B] = A;
	tam[A] += tam[B];
}

void dfs(int u, int p = 0)
{
	if (resp[u] != 1e9) return;
	resp[u] = t;
	for (int v : grafo[u]) if (v != p) dfs(v, u);
}

int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) resp[i] = 1e9, pai[i] = i, tam[i] = 1;


	stack<tuple<int, int> > pilha;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		freq[i][1] = (l[i] != -1);
		freq[i][2] = (r[i] != -1);
	}

	while (q--)
	{
		cin >> a >> b;
		pilha.push({a, (b == 1 ? l[a] : r[a])});
		freq[a][b] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (freq[i][1]) join(i, l[i]);
		if (freq[i][2]) join(i, r[i]);
	}

	while (!pilha.empty())
	{
		auto[a, b] = pilha.top(); pilha.pop();
		int um = find(1);

		if ((find(a) == um)^(find(b) == um))
		{	
			t = pilha.size();
			if (find(a) == um) dfs(b);
			else dfs(a);
		}

		join(a, b);
	}

	for (int i = 1; i <= n; i++) 
		cout << (resp[i] == 1e9 ? -1 : resp[i]) << endl;
}


