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

struct vertice
{
	int d, u, p;
	int operator >(vertice q) const{
		return d > q.d;
	}
};

int n, m, a, b, t, c, dist[501][2];
vector<par> grafo[501];
priority_queue<vertice, vector<vertice>, greater<vertice> > fila;

int dijkstra()
{
	for (int i = 0; i < n; i++)
		dist[i][0] = dist[i][1] = INF;
	dist[0][0] = 0;
	fila.push({0, 0, 0});
	while (!fila.empty())
	{
		auto[d, u, p] = fila.top(); fila.pop();
		if (d != dist[u][p]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (dist[v][p^1] > d + w)
			{
				dist[v][p^1] = d + w;
				fila.push({d + w, v, p^1});
			}
		}
	}

	return dist[n-1][0];
}

int main()
{_
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			grafo[i].clear();

		while (m--)
		{
			cin >> a >> b >> c;
			grafo[a].push_back({b, c});
			grafo[b].push_back({a, c});
		}

		cout << "Set #" << ++t << endl << (dijkstra()==INF?"?":to_string(dijkstra())) << endl;
	}
}






