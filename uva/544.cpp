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

int n, m, q, a, b, c, x, y, passou[501], ans, teste, pai[501], idx;
aresta arestas[19909];
vector<par> grafo[501];
map<string, int> mapa;
string k, l;

queue<par> fila;

int cmp(aresta a, aresta b)
{
    return a.z > b.z;
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
    fila.push(make_pair(a, 99999999));
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
                w = min(grafo[f][i].second, w);
                fila.push(make_pair(v, w));
            }
        }
    }

    return ans;
}

int main()
{_
    while (cin >> n >> m && n || m)
    {
        mapa.clear();
        idx = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> k >> l >> c;
            if (!mapa[k]) mapa[k] = ++idx;
            if (!mapa[l]) mapa[l] = ++idx;
            arestas[i].x = mapa[k];
            arestas[i].y = mapa[l];
            arestas[i].z = c;
        }

        kruskal();

        cin >> k >> l;

        cout << "Scenario #" << ++teste << endl;
        cout << bfs(mapa[k], mapa[l]) << " tons" << endl << endl;
    }
}