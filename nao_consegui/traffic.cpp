#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int w, x, y;
};

int t, n, m, a, b, c, pai[1010000], tam[1010000], ans, teste;
aresta grafo[1001000];

int cmp(aresta a, aresta b)
{
    return a.w > b.w;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}


int main()
{_
    while (cin >> n >> m && n)
    {
        ans = 9999999;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            grafo[i].x = a;
            grafo[i].y = b;
            grafo[i].w = c;
            pai[a] = a, pai[b] = b, tam[a] = 1, tam[b] = 1;
        }

        sort(grafo, grafo+m, cmp);

        for (int i = 0; i < m; i++)
        {
            a = id(grafo[i].x), b = id(grafo[i].y);
            if (a == b) continue;
            ans = min(ans, grafo[i].w);
            join(a, b);
            n--;
        }

        cin >> a >> b >> c;

        cout << "Scenario #" << ++teste << endl;
        cout << "Minimum Number of Trips = " << ceil((double) c / ans) << endl;
    }
}

