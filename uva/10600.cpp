#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int x, y, w;
};

int t, n, m, a, b, c, pai[101], ans;
aresta arestas[10100];
vector<int> tira;

int cmp(aresta a, aresta b)
{
    return a.w < b.w;
}

int id (int x)
{
    if (pai[x] == x) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    pai[a] = b;
}

int kruskal(int h)
{
    for (int i = 0; i <= n; i++)
        pai[i] = i;

    int x = 0, k = 0;
    for (int i = 0; i < m; i++)
    {
        a = id(arestas[i].x), b = id(arestas[i].y);
        if (a == b || i == h) continue;
        x += arestas[i].w;
        k++;
        join(a, b);
    }  

    return k == n - 1 ? x : INF; 
}

int main()
{_
    cin >> t;
    while (t--)
    {
        ans = 0;
        tira.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            pai[a] = a, pai[b] = b;
            arestas[i].x = a, arestas[i].y = b, arestas[i].w = c;
        }

        sort(arestas, arestas+m, cmp);

        for (int i = 0; i < m; i++)
        {
            a = id(arestas[i].x), b = id(arestas[i].y);
            if (a == b) continue;
            tira.push_back(i);
            ans += arestas[i].w;
            join(a, b);
        }   

        cout << ans << ' ';
        ans = INF;

        for (int i = 0; i < tira.size(); i++)
        {
            ans = min(ans, kruskal(tira[i]));
        }

        cout << ans << endl;
    }
}