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
#define MAX (int) (4e5 + 5)
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

int t, n, m, a, b, ciclo[MAX], dois[MAX], vis[MAX], k, resp[MAX];
vector<int> grafo[MAX];

void dfs(int u)
{
	vis[u] = 1;
	resp[u] = 1;
	for (int v : grafo[u])
	{
		if (vis[v] == 2) dois[v] = 1;
		else if (vis[v] == 1) ciclo[v] = 1;
		else dfs(v);
	}
	vis[u] = 2;
}

void dfs1(int u)
{
	resp[u] = -1, dois[u] = ciclo[u] = 0;
	for (int v : grafo[u])
		if (resp[v] != -1) dfs1(v);
}

void dfs2(int u)
{
	resp[u] = 2, dois[u] = 0;
	for (int v : grafo[u])
		if (resp[v] != 2 && resp[v] != -1) dfs2(v);
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		while (m--)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
		}

		dfs(1);
		for (int i = 1; i <= n; i++)
			if (ciclo[i]) dfs1(i);

		for (int i = 1; i <= n; i++)
			if (dois[i]) dfs2(i);

		for (int i = 1; i <= n; i++)
			cout << resp[i] << ' ';
		cout << endl;

		for (int i = 1; i <= n; i++)
		{
			grafo[i].clear();
			vis[i] = resp[i] = ciclo[i] = dois[i] = 0;
		}
	}
}	
