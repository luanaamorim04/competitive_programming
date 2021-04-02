#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, x, y, a, b, c, dist[MAXN], last[MAXN];
priority_queue<par, vector<par>, greater<par> > fila;
vector<par> grafo[100009];

void print_(int u)
{
    if (u == 0) return;
    print_(last[u]);
    cout << u << ' ';
}

int main()
{_  
    cin >> n >> m >> x >> y;
    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(par(b, c));
        grafo[b].push_back(par(a, c));
    }

    for (int i = 1; i <= n; i++) dist[i] = INF;

    fila.push(par(0, x));
    dist[x] = 0;
    while (!fila.empty())
    {
        int u = fila.top().second, d = fila.top().first; fila.pop();
        if (d != dist[u]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;
            if (u <= y && v != u + 1) continue;
            if (dist[v] > dist[u] + w) 
            {
                last[v] = u;
                dist[v] = dist[u] + w;
                fila.push(par(dist[v], v));
            }
        }
    }

    cout << dist[y] << endl;
    print_(y);
    cout << endl;
}