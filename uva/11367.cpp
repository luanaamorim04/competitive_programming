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
#define INF (1e9 + 5)
#define MAX (int) (2e3 + 5)
#define MOD 1000000007
#define MAXN (int) (1e3 + 5)
#define MAXF (int) 105
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

int n, m, a, b, c, t, q, arr[MAXN], dist[MAXN][MAXF];
vector<par> grafo[MAXN];
priority_queue<tuple<int, int, int> , vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > fila;

void dijkstra(int f, int a, int b)
{
	int resp = INF;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXF; j++)
			dist[i][j] = INF;

	dist[a][0] = 0;
	fila.push({0, a, 0});
	while (!fila.empty())
	{
		auto[d, u, g] = fila.top(); fila.pop(); // 100
		if (d != dist[u][g]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (g >= w && dist[v][g-w] > d)
			{
				dist[v][g-w] = d;
				fila.push({dist[v][g-w], v, g-w});	
			} 
		}

		if (g+1 <= f && dist[u][g+1] > d + arr[u]) 
		{
			dist[u][g+1] = d + arr[u];
			fila.push({dist[u][g] + arr[u], u, g+1});
		}
	}

	for (int i = 0; i <= f; i++)
		resp = min(resp, dist[b][i]);
	cout << (resp==INF ? "impossible" : to_string(resp)) << endl;
}

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	cin >> q;
	while (q--)
	{
		cin >> a >> b >> c;
		dijkstra(a, b, c);
	}
}












