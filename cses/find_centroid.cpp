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
#define MAX (int) (2e5 + 5)
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

int n, a, b, resp, sub[MAX];
vector<int> grafo[MAX];

void dfs(int u, int p = 0)
{
	int ok = 1;
	sub[u] = 1;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
		ok &= (sub[v] <= (n/2));
	}

	ok &= ((n-sub[u]) <= (n/2));
	if (ok) resp = u;
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1);
	cout << resp << endl;
}










