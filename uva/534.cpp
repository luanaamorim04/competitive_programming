#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int x, y, peso;
};

vector<pair<int, int> > grafo[2002];
queue<pair<int, int> > fila;
par pos[2002];
int n, a, b, idx, pai[2002], teste, passou[2002], ans;
aresta arestas[100009];

int dist(par a, par b);
int cmp(aresta a, aresta b);
int id(int x);

int main()
{_
    while (cin >> n && n)
    {
        idx = 0; ans = 0;
        for (int i = 1; i <= n; i++)
        {
            pai[i] = i;
            grafo[i].clear();
            passou[i] = 0;
            cin >> pos[i].first >> pos[i].second;
            for (int j = 1; j < i; j++)
            {
                arestas[idx].x = i;
                arestas[idx].y = j;
                arestas[idx++].peso = dist(pos[i], pos[j]);
            }
        }

        sort(arestas, arestas+idx, cmp);

        for (int i = 0; i < idx; i++)
        {
            a = arestas[i].x, b = arestas[i].y;
            if (id(a) == id(b)) continue;
            pai[id(a)] = id(b);
            grafo[a].push_back(make_pair(b, arestas[i].peso));
            grafo[b].push_back(make_pair(a, arestas[i].peso));
        }

        fila.push(make_pair(0, 1));
        passou[1] = 1;
        while (!fila.empty())
        {
            int f = fila.front().second;
            int w = fila.front().first; fila.pop();

            if (f == 2) ans = w;

            for (int i = 0; i < grafo[f].size(); i++)
            {
                int v = grafo[f][i].first;
                int y = grafo[f][i].second;
                if (!passou[v])
                {
                    passou[v] = 1;
                    w = max(w, y);
                    fila.push(make_pair(w, v));
                }
            }
        }

        cout << "Scenario #" << ++teste << endl << "Frog Distance = ";
        cout << fixed << setprecision(3) << sqrt(ans) << endl << endl;
    }
}

int dist(par a, par b)
{
    int x = (a.first - b.first);
    int y = (a.second - b.second);
    x *= x; y *= y;
    return (x + y);
}

int cmp(aresta a, aresta b)
{
    return a.peso < b.peso;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}