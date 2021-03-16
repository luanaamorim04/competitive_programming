#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#define INF 1562500
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, p, k, a, b, c, dist[300], ans, parou, tmp;
priority_queue<par, vector<par>, greater<par> > fila;
vector<int> grafo[300];
map<par, int> peso;
set<par> caminho;

int dijkstra();

int main()
{_
    while (cin >> n >> m >> c >> k && n)
    {
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        caminho.clear();
        while (!fila.empty()) fila.pop();

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> p;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            peso[make_pair(a, b)] = p;
            peso[make_pair(b, a)] = p;

            int x = max(a, b), y = min(a, b);
            if (x < c && x == y + 1) 
                caminho.insert(make_pair(a, b));
        }
        
        cout << dijkstra() << endl;
    }
}

int dijkstra()
{
    for (int i = 0; i <= n; i++)
        dist[i] = INF;

    fila.push(make_pair(0, k));
    dist[k] = 0;
    while (!fila.empty())
    {
        int d = fila.top().first, u = fila.top().second; fila.pop();

        if (d > dist[u]) continue;

        if (u < c - 1)
        {
            for (set<par>::iterator it = caminho.begin(); it != caminho.end(); it++)
            {
                par x = *it;
                if (min(x.first, x.second) < u) continue;
                d += peso[x];
            }

            dist[c - 1] = min(dist[c - 1], d);
            continue;
        }
        else if (u == c - 1)
            return dist[c - 1];


        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            int w = peso[make_pair(u, v)];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[c - 1];
}