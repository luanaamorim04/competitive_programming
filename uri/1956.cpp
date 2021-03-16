#include <iostream>
#include <algorithm>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct vertice
{
    int a, b, w;
};

int n, pai[10009], tam[10009], j, c, k, comp, idx;
long long ans;
vertice v[1000900], x;

int cmp(vertice a, vertice b)
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

int main()
{_
    cin >> n;
    pai[n] = n;
    tam[n] = 1;
    
    for (int i = 1; i < n; i++)
    {
        pai[i] = i;
        tam[i] = 1;
        cin >> k;
        while (k--)
        {
            cin >> j >> c;
            v[idx].a = i; v[idx].b = j; v[idx].w = c; 
            idx++;
        }
    }

    sort(v, v+idx, cmp);

    for (int i = 0; i < idx; i++)
    {
        int A = id(v[i].a), B = id(v[i].b);
        if (A == B) continue;
        comp++;
        ans += v[i].w;
        join(A, B);
    }
    cout << n - comp << ' ' << ans << endl;
}