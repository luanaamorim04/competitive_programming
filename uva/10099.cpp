#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int x, y, w;
};

int n, m, pai[101], a, b, c, ans, menor, s, d, t, passou[101], teste;
vector<int> grafo[101];
aresta arestas[10100];
queue<par> fila;
map<par, int> peso;

int cmp(aresta a, aresta b)
{
    return a.w > b.w;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

int main()
{_
    while (cin >> n >> m && (n || m))
    {
        peso.clear();
        for (int i = 0; i <= n; i++)
        {
            grafo[i].clear();
            pai[i] = i;
            passou[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            peso[make_pair(a, b)] = c;
            peso[make_pair(b, a)] = c;
            arestas[i].x = a, arestas[i].y = b, arestas[i].w = c;
        }

        sort(arestas, arestas+m, cmp);

        for (int i = 0; i < m; i++)
        {
            a = arestas[i].x, b = arestas[i].y;
            if (id(a) == id(b)) continue;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            pai[id(a)] = id(b);
        }

        cin >> s >> d >> t;

        fila.push(make_pair(INF, s));
        passou[s] = 1;
        while (!fila.empty())
        {
            int f = fila.front().second, x = fila.front().first; fila.pop();

            if (f == d)
            {
                ans = x-1;
            }

            for (int i = 0; i < grafo[f].size(); i++)
            {
                int v = grafo[f][i];
                if (!passou[v])
                {
                    int tmp = min(x, peso[make_pair(f, v)]);
                    passou[v] = 1;
                    fila.push(make_pair(tmp, v));
                }
            }
        }
        
        cout << "Scenario #" << ++teste << endl;
        cout << "Minimum Number of Trips = " << ceil((double) (t) / ans) << endl << endl;
    }
}