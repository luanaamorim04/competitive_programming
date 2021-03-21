#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int x, y, z;
};

int n, m, q, a, b, c, x, y, passou[101], ans, teste, pai[101];
aresta arestas[1009];
vector<par> grafo[101];

queue<par> fila;

int cmp(aresta a, aresta b)
{
    return a.z < b.z;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void kruskal()
{
    for (int i = 0; i <= n; i++)
    {
        pai[i] = i;
        grafo[i].clear();
        passou[i] = 0;
    }

    sort(arestas, arestas+m, cmp);

    for (int i = 0; i < m; i++)
    {
        int a = arestas[i].x, b = arestas[i].y, c = arestas[i].z;
        if (id(a) == id(b)) continue;
        pai[id(a)] = id(b);
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }
}

int bfs(int a, int b)
{
    int ans = -1;
    for (int i = 0; i <= n; i++)
        passou[i] = 0;

    fila.push(make_pair(a, 0));
    passou[a] = 1;
    while (!fila.empty())
    {
        int f = fila.front().first, w = fila.front().second; fila.pop();

        if (f == b) ans = w;

        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i].first;
            if (!passou[v])
            {
                passou[v] = 1;
                w = max(grafo[f][i].second, w);
                fila.push(make_pair(v, w));
            }
        }
    }

    return ans;
}

int main()
{_
    while (cin >> n >> m >> q && n)
    {
        if (teste) cout << endl;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            arestas[i].x = a;
            arestas[i].y = b;
            arestas[i].z = c;
        }

        kruskal();

        cout << "Case #" << ++teste << endl;

        while (q--)
        {
            cin >> x >> y;
            ans = bfs(x, y);
            if (ans == -1)
                cout << "no path\n";
            else
                cout << ans << endl;
        }
    }
}