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

int n, dist[1009];
vector<par> grafo[1009];
priority_queue<par, vector<par>, greater<par> > fila;
struct rect
{
    int x1, y1, x2, y2;
};

rect areas[1009];

int dist_(rect a, rect b);

int main()
{_  
    for (int i = 0; i < 2; i++)
    {
        cin >> areas[i].x1 >> areas[i].y1;
        areas[i].x2 = areas[i].x1, areas[i].y2 = areas[i].y1;
    }

    cin >> n;
    for (int i = 2; i < n + 2; i++)
        cin >> areas[i].x1 >> areas[i].y1 >> areas[i].x2 >> areas[i].y2;

    for (int i = 0; i < n + 2; i++)
    {
        dist[i] = INF;
        for (int j = i + 1; j < n + 2; j++)
        {
            int x = dist_(areas[i], areas[j]);
            grafo[i].push_back(par(j, x));
            grafo[j].push_back(par(i, x));
        }
    }

    fila.push(par(0, 0));
    dist[0] = 0;
    while (!fila.empty())
    {
        int d = fila.top().first, u = fila.top().second; fila.pop();
        if (dist[u] != d) continue;
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(par(dist[v], v));
            }
        }
    } 
    cout << dist[1] << endl;
}

int dist_(rect a, rect b)
{
    int ans;
    if (a.y1 > b.y1) swap(a, b);
    if (b.y1 < a.y2) ans = 0;
    else ans = b.y1 - a.y2;
    if (a.x1 > b.x1) swap(a, b);
    if (b.x1 < a.x2) return ans;
    return ans + b.x1 - a.x2;
}