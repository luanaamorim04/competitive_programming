#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<long long, long long>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, a, b, c, t, dist[909], k, u, d, v, w;
vector<par> grafo[902];
priority_queue<par, vector<par>, greater<par> > fila;

int dijkstra(int x)
{
    fila.push(make_pair(0, x));
    dist[x] = 0;

    while (!fila.empty())
    {
        u = fila.top().second, d = fila.top().first; fila.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            v = grafo[u][i].first, w = grafo[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[n + x - 1];
}

int main()
{_
    while (cin >> n >> m)
    {
        for (int i = 0; i <= 810; i++)
        {
            if (grafo[i].size()) grafo[i].clear();
            dist[i] = INF;
        }
 
        while (m--)
        { 
            cin >> a >> b >> t >> c;
            if (t)
            {
                grafo[a].push_back(make_pair(b, c));
            }
            else
            {
                grafo[a+n].push_back(make_pair(b+n, c));
            }
        }

        cout << min(dijkstra(1), dijkstra(n + 1)) << endl;
    }
}