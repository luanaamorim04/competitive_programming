#include <iostream>
#include <vector>
#include <queue>
#define ii pair<long long, long long>
#define INF 1e15

using namespace std;

vector<ii> grafo[100009];
long long dist[100009], n, m, a, b, c;
priority_queue<ii, vector<ii>, greater<ii> > fila;

int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(ii(b, c));
    }

    for (int i = 2; i <= n; i++)
        dist[i] = INF;

    fila.push(ii(0, 1));
    while (!fila.empty())
    {
        long long d = fila.top().first, u = fila.top().second; fila.pop();
        if (d != dist[u]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(ii(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';

    cout << endl;
}