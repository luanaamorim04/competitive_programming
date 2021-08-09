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
#define INF (ll) (1e15)
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
	ll u, d, p;

	int operator>(vertice q) const{
		return d>q.d;
	}
};

ll dist[MAX][2];
int n, m, a, b, c;
vector<par> grafo[MAX];
priority_queue<vertice, vector<vertice>, greater<vertice> > fila;

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	for (int i = 2; i <= n; i++)
		dist[i][0] = dist[i][1] = INF;
	
	fila.push({1, 0, 0});
	while (!fila.empty())
	{
		auto[u, d, p] = fila.top(); fila.pop();
		if (dist[u][p] != d) continue;
		for (auto[v, w] : grafo[u])
		{
			if (dist[v][p^1] > dist[u][p] + w)
			{
				dist[v][p^1] = dist[u][p] + w;
				fila.push({v, dist[v][p^1], p^1});
			}
		}
	}

	cout << (dist[n][0] == INF ? -1 : dist[n][0]) << endl;
}



















