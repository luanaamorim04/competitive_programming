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
#define INF (1e9)
#define MAXN ((int) (8e5))
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

struct pergunta
{
	int u, l, r;
};

vector<int> grafo[MAXN], vrtx;
pergunta q[MAXN];
int n, m, vis[MAXN];

void build(int idx, int i, int j)
{
	if (i == j) return;
	grafo[idx].push_back(esq(idx));
	grafo[idx].push_back(dir(idx));
	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void achar(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		vrtx.push_back(idx);
		return;
	}
	int mid = ((i+j)>>1);
	achar(esq(idx), i, mid, l, r);
	achar(dir(idx), mid+1, j, l, r);
}

int dfs(int u)
{
	int ans = 0;
	vis[u] = 1;
	for (int v : grafo[u])
	{
		if (vis[v] == 1) return 1;
		if (!vis[v]) ans |= dfs(v);
	}

	vis[u] = 2;
	return ans;
}

int f(int x)
{	
	for (int i = 1; i < MAXN; i++)
		grafo[i].clear();

	build(1, 1, n);
	int ans = 0;

	for (int i = 1; i <= x; i++)
	{
		vrtx.clear();
		achar(1, 1, n, q[i].u, q[i].u);
		int a = *vrtx.begin();
		vrtx.pop_back();
		achar(1, 1, n, q[i].l, q[i].r);
		for (int b : vrtx) grafo[a].push_back(b);
	}

	memset(vis, 0, sizeof(vis));
	for (int i = 1; i < MAXN; i++)
		if (!vis[i]) ans |= dfs(i);

	return ans;
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> q[i].u >> q[i].l >> q[i].r;
	
	int ini = 1, meio, fim = m;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(meio)) fim = meio - 1;
		else ini = meio + 1;
	}

	cout << (fim == m ? -1 : fim + 1) << endl;
}














