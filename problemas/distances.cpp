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

int t, n, a, b, vis[MAX];
vector<int> grafo[MAX];

void dfs(int u, int p, int nivel)
{
	vis[u] = 1;
	if (!nivel) cout << u << ' ';

	for (int v : grafo[u])
	{
		if (v != p)
		{
		 	dfs(v, u, nivel^1);
		}
	}

	vis[u] = 2;
	if (nivel) cout << u << ' ';
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		vis[0]  = 1;
		for (int i = 1;i < n; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		dfs(1, 0, 0);
		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			grafo[i].clear();
			vis[i] = 0;
		}
	}


}	







