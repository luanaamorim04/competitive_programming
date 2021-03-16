#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct vertice
{
    int a, b, c;
};

int n, m, ans, k, pai[1001], tam[1001];
vertice v[1000009];

int cmp(vertice A, vertice B)
{
    return A.c < B.c;
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
    while (cin >> n >> m)
    {
        ans = 0, k = 0;
        for (int i = 0; i <= n; i++)
        {
            pai[i] = i;
            tam[i] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> v[i].a >> v[i].b >> v[i].c;
        }

        sort(v, v+m, cmp);

        for (int i = 0; i < m; i++)
        {
            int A = id(v[i].a), B = id(v[i].b);
            if (A == B) continue;
            join(A, B);
            k++;
            ans += v[i].c;
        }

        if (k < n - 1) cout << "impossivel" << endl;
        else cout << ans << endl;
    }
}