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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

queue<par> fila;
vector<int> grafo[1<<20];
int n, a, b, v1, v2, nivel[1<<20], resp[1<<20];

int bfs(int x)
{
	int d = 0;
	fila.push({x, 0});
	nivel[x] = 0;
	while (!fila.empty())
	{
		int u = fila.front().first, p = fila.front().second; fila.pop();
		for (int v : grafo[u])
		{
			if (v == p) continue;
			resp[v] = max(resp[v], nivel[u] + 1);
			nivel[v] = nivel[u] + 1;
			fila.push({v, u});
		}

		if (nivel[d] < nivel[u]) d = u;
	}

	return d;
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

	v1 = bfs(1);
	v2 = bfs(v1);
	bfs(v2);

	for (int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << endl;
}















