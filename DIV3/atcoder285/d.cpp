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
#define dbug(x) cout << (#x) << " -> " << x << endl
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

map<string, int> val;
int m, n, vis[MAX];
vector<int> grafo[MAX];

int dfs(int u)
{
	vis[u] = 1;
	int r = 0;
	for (int v : grafo[u])
	{
		if (vis[v] == 1) return 1;
		else if (vis[v] == 2) continue;
		r |= dfs(v);
	}

	vis[u] = 2;
	return r;
}

int main()
{_
	cin >> m;
	while (m--)
	{
		string a, b;
		cin >> a >> b;
		if (val.find(a) == val.end()) val[a] = ++n;
		if (val.find(b) == val.end()) val[b] = ++n;
		grafo[val[a]].push_back(val[b]);
	}

	int r = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) r |= dfs(i);
	cout << (r?"No":"Yes") << endl;
}
