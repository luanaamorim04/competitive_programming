#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF (int) (1e8 + 1)
#define par pair<int, pair<int, int> >

using namespace std;

int n, m, q, s, t, a, b, menor, dist[10009][101], w;
priority_queue<par, vector<par>, greater<par> > fila;
map<pair<int, int>, int> mapa;
vector<pair<int, int> > grafo[10009];

void dijkstra()
{
    fila.push(par(0, make_pair(s, 0)));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 100; j++)
            dist[i][j] = INF;
    
    dist[s][0] = 0;
    while (!fila.empty())
    {
        int u = fila.top().second.first, d = fila.top().first, a = fila.top().second.second;
        fila.pop();
        if (d != dist[u][a]) continue;
    
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;
            if (mapa[make_pair(u, v)] && dist[v][a] > d + w) 
            {
                dist[v][a] = d + w;
                fila.push(par(dist[v][a], make_pair(v, a)));
            }
            else if (!mapa[make_pair(u, v)] && dist[v][a + 1] > d + w)
            {
                dist[v][a + 1] = d + w;
                fila.push(par(dist[v][a + 1], make_pair(v, a + 1)));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> q >> s >> t;
    while (cin >> b)
    {
        mapa[make_pair(a, b)] = 1;
        if (b == t) break;
        a = b;
    }

    while (m--)
    {
        cin >> a >> b >> w;
        grafo[a].push_back(make_pair(b, w));
        if (mapa[make_pair(a, b)]) menor += w;
    }

    dijkstra();

    while (q--)
    {
        int ok = 0;
        cin >> a >> b;
        for (int i = a; i < 101; i++)
            if (dist[t][i] <= menor + b) ok = 1;
        cout << (ok ? 'S' : 'N') << endl;
    }
}