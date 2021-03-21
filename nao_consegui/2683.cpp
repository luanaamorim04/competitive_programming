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

int n, m, ans, k, pai[3001], tam[3001], ans1;
vertice v[2000009];

int cmp(vertice A, vertice B)
{
    return A.c < B.c;
}

int cmp1(vertice A, vertice B)
{
    return A.c > B.c;
}

int id(int x, int y)
{
    if (x == pai[x + y]) return x;
    return pai[x + y] = id(pai[x + y], y);
}

void join(int a, int b, int y)
{
    if (tam[a + y] > tam[b + y]) swap(a, b);
    pai[a + y] = b + y;
    tam[b + y] += tam[a + y];
}

int main()
{_
    cin >> m;
    ans = 0, k = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i + m] = v[i];
        n = max(n, max(v[i].a, v[i].b));
    }

    for (int i = 0; i <= n; i++)
    {
        pai[i] = i;
        pai[i + n] = i;
        tam[i + n] = 1;
        tam[i] = 1;
    }

    sort(v, v+m, cmp);
    sort(v+m, v+2*m, cmp1);

    for (int i = 0; i < m; i++)
    {
        int A = id(v[i].a, 0), B = id(v[i].b, 0);
        int C = id(v[i + m].a, n), D = id(v[i + m].b, n);
        //cout << v[i].c << ' ' << v[i + m].c << endl;
        if (A != B)
        {
            join(A, B, 0);
            ans += v[i].c;
        }
        if (C != D)
        {
            join(C, D, n);
            //cout << id(C, n) << ' ' << id(D, n) << endl;
            ans1 += v[i + m].c;
        }
    }

    cout << ans1 << endl << ans << endl;
}