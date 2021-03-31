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

vector<int> grafo[1<<20];
queue<int> fila;
int n, m, k, x, v[1<<20], dist[1<<20];

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> x;
			grafo[n + i].push_back(x);
			grafo[x].push_back(n + i);
		}
	}

	fila.push(1);
	dist[1] = 1;
	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int i = 0; i < grafo[u].size(); i++)
		{
			int v = grafo[u][i];
			if (dist[v]) continue;
			fila.push(v);
			dist[v] = dist[u] + 1;
		}
	}

	cout << (dist[n]-1)/2 << endl;
}
