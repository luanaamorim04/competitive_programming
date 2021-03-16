#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, pai[200009], tam[200009], a, b;
long long ans, c;

struct aresta
{   
    int x, y;
    long long w;
};
aresta grafo[200009];

int cmp(aresta a, aresta b)
{
    return a.w < b.w;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (a == b) return;
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}

int main()
{_
    while (cin >> n >> m && n || m)
    {
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            pai[a] = a, pai[b] = b, tam[a] = 1, tam[b] = 1;
            grafo[i].x = a;
            grafo[i].y = b;
            grafo[i].w = c;
        }

        sort(grafo, grafo+m, cmp);

        for (int i = 0; i < m; i++)
        {
            int a = id(grafo[i].x), b = id(grafo[i].y);
            if (a == b)
            {
                ans += grafo[i].w;
                continue;
            }

            join(a, b);
        }   

        cout << ans << endl;
    }
}