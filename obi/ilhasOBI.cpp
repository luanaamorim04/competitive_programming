#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, b, c, n, m, dist[1001], s, maior, menor;
vector<par>grafo[1001];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        dist[a] = INF;
        dist[b] = INF;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }

    cin >> s;
    dist[s] = 0;
    menor = INF;
    fila.push(make_pair(0, s));
    while (!fila.empty())
    {
        int u = fila.top().second, d = fila.top().first; fila.pop();

        if (dist[u] < d) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int w = grafo[u][i].second;
            int v = grafo[u][i].first;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        maior = max(maior, dist[i]);
        if (i == s) continue;
        menor = min(menor, dist[i]);
    }

    cout << maior - menor << endl;
}