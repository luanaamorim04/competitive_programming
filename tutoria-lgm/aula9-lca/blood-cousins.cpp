#include <iostream>
#include <vector>
#define MAXL 20
#define MAXN (int)(2e5 + 10)
#define ii pair<int, int> 
#define esq(x) (x<<1)
#define dir(x) ((x<<1) | 1)
#define all(x) x.begin(), x.end()

using namespace std;

int t, up[MAXN][MAXL], tin[MAXN], tout[MAXN], n, a, b, q, dist[MAXN];
vector<ii> nivel[MAXN];
vector<int> grafo[MAXN];

struct tree
{
	vector<int> v;
};

vector<tree> st[MAXN];

tree join(tree esq, tree dir)
{
	tree resp;
	int i1 = 0, i2 = 0;
	while (i1 < esq.v.size() || i2 < dir.v.size())
	{
		if (i1 == esq.v.size()) resp.v.push_back(dir.v[i2++]);
		else if (i2 == dir.v.size()) resp.v.push_back(esq.v[i1++]);
		else if (esq.v[i1] < dir.v[i2]) resp.v.push_back(esq.v[i1++]);
		else resp.v.push_back(dir.v[i2++]);
	}

	return resp;
}

void build(int t, int idx, int i, int j)
{
	if (i == j)
	{
		st[t][idx].v.push_back(nivel[t][i].second);
		return;
	}	
	int mid = (i+j)/2;
	build(t, esq(idx), i, mid);
	build(t, dir(idx), mid+1, j);
	st[t][idx] = join(st[t][esq(idx)], st[t][dir(idx)]);
}

int query(int t, int idx, int i, int j, int pos, int val)
{
	if (i >= pos)
	{
		int ini = 0, meio, fim = st[t][idx].v.size()-1;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (st[t][idx].v[meio] <= val) ini = meio + 1;
			else fim = meio - 1;
		}	
		return ini;
	}
	int mid = (i+j)/2;
	if (j < pos) return 0;
	int x = query(t, esq(idx), i, mid, pos, val);
	int y = query(t, dir(idx), mid+1, j, pos, val);
	return x+y;
}

void dfs(int u, int p = 0)
{
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];
	tin[u] = ++t;
	dist[u] = dist[p] + 1;

	for (int v : grafo[u])
		if (v != p) dfs(v, u);
	tout[u] = ++t;
	nivel[dist[u]].push_back({tin[u], tout[u]});
}

void cria()
{
	for (int i = 1; i <= n; i++)
		if (!tin[i]) dfs(i);
	for (int i = 1; i <= n; i++)
	{
		sort(all(nivel[i]));
		st[i].resize((nivel[i].size())<<2);
		if (!nivel[i].empty()) build(i, 1, 0, nivel[i].size()-1);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> up[i][0];
		if (up[i][0])
		{
			grafo[up[i][0]].push_back(i);
			grafo[i].push_back(up[i][0]);
		}
	}

	cria();
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		int d = dist[a];
		for (int i = MAXL-1; i >= 0; i--)
		{
			if ((1<<i) <= b)
			{
				b -= (1<<i);
				a = up[a][i];
			}
		}

		if (!a) 
		{
			cout << 0 << ' ';
			continue;
		}

		int ini = 0, meio, fim = nivel[d].size() - 1;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (nivel[d][meio].first >= tin[a]) fim = meio - 1;
			else ini = meio + 1;
		}
		int menor_tin = fim + 1;

		cout << query(d, 1, 0, nivel[d].size()-1, menor_tin, tout[a]) - 1<< ' ';
	}
	cout << endl;
	return 0;
}
