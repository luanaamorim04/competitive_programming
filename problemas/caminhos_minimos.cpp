#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 1e15
#define MOD 1000000007
#define par pair<long long, long long>
#define MAXN (int) 2e4 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, nivel[MAXN];
long long dist[MAXN][2];
vector<par> grafo[MAXN];
priority_queue<par, vector<par>, greater<par> > pq;

int dijkstra(long long x);
void bfs();

int main()
{_  
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }

    bfs();
    long long ini = 0, fim = 1e9, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (dijkstra(meio)) fim = meio - 1;
        else ini = meio + 1;
    }

    cout << (fim != (int) 1e9 ? fim + 1 : -1) << endl;
}

int dijkstra(long long x)
{
    for (int i = 0; i <= n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = 0;
    }

    pq.push(make_pair(0, 1));
    dist[1][0] = 0;
    while (!pq.empty())
    {
        long long d = pq.top().first, u = pq.top().second; pq.pop();
        if (d > dist[u][0]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            long long v = grafo[u][i].first, w = grafo[u][i].second + x;
            if (dist[v][0] > dist[u][0] + w)
            {
                dist[v][1] = dist[u][1] + 1;
                dist[v][0] = dist[u][0] + w;
                pq.push(make_pair(dist[v][0], v));
            }
            else if (dist[v][0] == dist[u][0] + w)
            {
                dist[v][1] = min(dist[u][1] + 1, dist[v][1]);
                pq.push(make_pair(dist[v][0], v));
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (dist[i][1] != nivel[i] - 1) return 0;
    return 1;
}

void bfs()
{
    queue<int> fila;
    fila.push(1);
    nivel[1] = 1;
    while (!fila.empty())
    {
        long long u = fila.front(); fila.pop();
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first;
            if (!nivel[v])
            {
                nivel[v] = nivel[u] + 1;
                fila.push(v);
            }
        }
    }
}