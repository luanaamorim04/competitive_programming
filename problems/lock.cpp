#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define MAX 5000000
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct vertice
{
    int a, b, w;
};

vertice v[MAX], x, tmp;
int t, n, pai[MAX], tam[MAX], keys[MAX], idx, ans;
int peso(int A, int B);
int id(int x);
int cmp(vertice a, vertice b);
void join(int a, int b);

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        pai[0] = 0; tam[0] = 1; ans = 0; idx = 0;
        int dist = 99999;

        for (int i = 1; i <= n; i++)
        {
            cin >> keys[i];
            pai[keys[i]] = keys[i];
            tam[keys[i]] = 1;
            for (int j = 1; j < i; j++)
            {
                x.a = keys[i], x.b = keys[j], x.w = peso(x.a, x.b);
                v[idx++] = x;
            }

            if (peso(0, keys[i]) < dist)
            {
                dist = peso(0, keys[i]);
                tmp.a = 0, tmp.b = keys[i], tmp.w = dist;
            }
        }

        v[idx++] = tmp;
        sort(v, v+idx, cmp);

        for (int i = 0; i < idx; i++)
        {
            int A = id(v[i].a), B = id(v[i].b);
            if (A == B) continue;
            join(A, B);
            ans += v[i].w;
        }

        cout << ans << endl;
    }
}

int peso(int A, int B)
{
    int w = 0, a[4], b[4], x, y;
    for (int i = 0; i < 4; i++)
    {
        a[i] = A%10; b[i] = B%10;
        A /= 10; B /= 10;
        x = max(a[i], b[i]); y = min(a[i], b[i]);
        w += min(x - y, 9 - x + y - 0 + 1);
    }

    return w;
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

int cmp(vertice a, vertice b)
{
    return a.w < b.w;
}

void join(int a, int b)
{
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += a;
}