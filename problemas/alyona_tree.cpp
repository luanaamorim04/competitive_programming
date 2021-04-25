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
#define MAX (int) (2e5 + 10)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[MAX];
ll n, s, b, a[MAX], up[MAX][22], soma[MAX][22], d[MAX];

void dfs(int u)
{
	for (int v : grafo[u])
	{
		dfs(v);
		d[u] += d[v];
	}
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int v = 2; v <= n; v++)
	{
		cin >> up[v][0] >> soma[v][0];
		grafo[up[v][0]].push_back(v);
	}

	for (int i = 1; i < 22; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (!up[j][i-1]) continue;
			up[j][i] = up[up[j][i-1]][i-1];
			soma[j][i] = soma[j][i-1] + soma[up[j][i-1]][i-1];
		}
	}

	for (int u = 2; u <= n; u++)
	{
		int v = u;
		s = 0;
		for (int i = 21; i >= 0; i--)
		{
			if (!up[v][i] || s+soma[v][i] > a[u]) continue;
			s += soma[v][i];
			v = up[v][i];
		}

		d[up[u][0]]++;
		d[up[v][0]]--;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << endl;
}









