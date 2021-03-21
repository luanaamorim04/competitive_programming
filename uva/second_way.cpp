#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int x, y, w;
};

int t, n, m, pai[1001], tam[1001], a, b, c, ans, conexo, second, idx, k[1001], ok, teste;
aresta v[1001];

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
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}

int kruskal(int h)
{
    int soma = 0, j = 0;
    for (int i = 0; i <= n; i++)
    {
        pai[i] = i;
        tam[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int a = id(v[i].x), b = id(v[i].y);
        if (a == b) continue;
        if (i == k[h]) continue;
        soma += v[i].w;
        j++;
        join(a, b);
    }

    if (j < n - 1) return INF;
    return soma;
}   

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ok = 0, ans = INF, idx = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            pai[a] = a, tam[a] = 1;
            pai[b] = b, tam[b] = 1;
            v[i].x = a; v[i].y = b; v[i].w = c;
        }

        sort(v, v+m, cmp);

        for (int i = 0; i < m; i++)
        {
            a = id(v[i].x), b = id(v[i].y);
            if (id(a) == id(b))
            {
                ok = 1;
                continue;
            }
            k[idx++] = i;
            ans += v[i].w;
            join(a, b);
        }

        for (int i = 0; i < idx; i++)
        {
            ans = min(ans, kruskal(i));
        }

        cout << "Case #" << ++teste << " : ";


        if (idx != n - 1)
            cout << "No way\n";
        else if (!ok)
            cout << "No second way\n";
        else
            cout  << ans << endl;


            
    }
}