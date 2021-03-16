#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, dist[10009], x, y;
vector<par> grafo[10009];
priority_queue<par, vector<par>, greater<par> > fila;

int dijkstra(int a, int b)
{
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
    }

    fila.push(make_pair(0, a));
    dist[a] = 0;

    while (!fila.empty())
    {
        int u = fila.top().second, d = fila.top().first; fila.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first;
            int w = grafo[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[b];
}

int main()
{_
    cin >> n >> m >> a >> b;
    while (m--)
    {
        cin >> x >> y;
        grafo[x].push_back(make_pair(y, 0));
        grafo[y].push_back(make_pair(x, 1));
    }

    x = dijkstra(a, b);
    y = dijkstra(b, a);

    if (x == y)
        cout << "Bibibibika\n";
    else if (x < y) 
        cout << "Bibi: " << x << endl;
    else
        cout << "Bibika: " << y << endl;

}