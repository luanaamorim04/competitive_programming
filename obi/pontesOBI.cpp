#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, dist[1009], a, b, c;
vector<par> grafo[1009];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        dist[a] = INF;
        dist[b] = INF;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }

    fila.push(make_pair(0, 0));
    dist[0] = 0;
    while (!fila.empty())
    {
        int d = fila.top().first, u = fila.top().second; fila.pop();

        if (d > dist[u]) continue;
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    cout << dist[n + 1] << endl;
}