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
#define MAX (int) (3e3)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
vector<int> grafo[MAX];
int n, m, resp, nivel[MAX], a, b, x, r;
vector<par> arestas, ciclo;
queue<par> fila;
 
void bfs(int x)
{
	fila.push({x, 0});
	memset(nivel, 0, sizeof(nivel));
	nivel[x] = 1;
	while (!fila.empty())
	{
		int u = fila.front().first, p = fila.front().second; fila.pop();
		for (int v : grafo[u])
		{
			if (v == p) continue;
			if (!nivel[v])
			{
				nivel[v] = nivel[u] + 1;
				fila.push({v, u});
			}
			else
			{
				resp = min(resp, nivel[v] + nivel[u] - 1);
			}
		}
	}
}
 
int main()
{_
	cin >> n >> m;
	resp = INF;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i);
 
	cout << (resp == INF ? -1 : resp) << endl;
}
















