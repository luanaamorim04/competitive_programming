#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 20000
#define INF 10000000
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<pair<int, int> > grafo[MAX];
int n, m, N, s, u, dist[MAX], proc[MAX], ult[MAX], a, b, c;

void dijkstra(int x)
{
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
        proc[i] = 0;
        ult[i] = -1;
    }

    dist[s] = 0;

    for (int i = 0; i < n; i++)
    {
        u = n;
        for (int j = 0; j < n; j++)
        {
            if (!proc[j] && dist[j] <= dist[u])
            {
                u = j;
            }
        }

        proc[u] = 1;

        for (int j = 0; j < grafo[u].size(); j++)
        {
            int w = grafo[u][j].second;
            int v = grafo[u][j].first;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                ult[v] = u;
            }
        }
    }
}

int main()
{_
    cin >> N;
    while (N--)
    {
        cin >> n >> m >> s >> u;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            grafo[a].push_back(make_pair(b, c));
            grafo[b].push_back(make_pair(a, c));
        }
        dijkstra(s);
        cout << dist[u] << endl;
    }
}