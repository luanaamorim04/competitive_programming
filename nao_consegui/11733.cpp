#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define MAX 100
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct aresta
{
    int A, B, w;
};

int t, n, m, a, x, y, c, aero[MAX], pai[MAX], ans, voa;
aresta arestas[MAX];

int id(int x)
{
    if (x == pai[x]) return x;
    return id(pai[x]);
}

int cmp(aresta a, aresta b)
{
    return a.w < b.w;
}

void join(int a, int b)
{
    pai[a] = b;
    aero[b] = max(aero[a], aero[b]);
}

int main()
{_
    cin >> t;
    for (int h = 1; h <= t; h++)
    {
        cin >> n >> m >> a;
        ans = 0; voa = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            arestas[i].A = x, arestas[i].B = y, arestas[i].w = c;
            pai[x] = x;
            pai[y] = y;
        }

        sort(arestas, arestas+m, cmp);

        for (int i = 0; i < m; i++)
        {
            int u = id(arestas[i].A), v = id(arestas[i].B), rua = arestas[i].w;
            if (aero[u] && aero[v]) continue;
            if (!aero[u] && !aero[v])
            {
                if (rua >= a)
                {
                    voa += 2;
                    ans += 2*a;
                }
                else
                {
                    ans += a + rua;
                    voa++;
                    join(u, v);
                }
            }
            // else if (rua >= a)
            // {
            //     voa++;
            //     ans += a;
            // }
            // else
            // {
            //     ans += rua;
            //     join(u, v);
            // }

            // aero[u] = 1;
            // aero[v] = 1;
        }

        //cout << "Case #" << h << " : " << ans << ' ' << voa << endl;
    }
}