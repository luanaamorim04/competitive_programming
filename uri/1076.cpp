#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<10];
int ans, a, b, k, n, m, t, passou[1<<10];

void dfs(int u)
{
	passou[u] = 1;
	ans++;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		int v = grafo[u][i];
		if (!passou[v]) dfs(v);
	}
}

int main()
{_
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> k;
		cin >> n >> m;
		while (m--)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		dfs(k);
		cout << (ans - 1)*2 << endl;
		for (int i = 0; i <= n; i++)
			grafo[i].clear();

		memset(passou, 0, sizeof(passou));
	}
}
