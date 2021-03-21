#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#define MAX 50090
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, pai[MAX], tam[MAX], k, ans, x, y;
map<string, int> mapa;
string s, a, b;

int id(int x)
{
    if (pai[x] == x) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (a == b) return;
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
    ans = max(ans, tam[b]);
}

int main()
{_
    while (cin >> n >> m && n || m)
    {
        ans = 1;
        mapa.clear();
        k = 0;
        while (n--)
        {
            cin >> s;
            mapa[s] = ++k;
            pai[k] = k;
            tam[k] = 1;
        }
        while (m--)
        {
            cin >> a >> b;
            x = id(mapa[a]), y = id(mapa[b]);
            join(x, y);
        }

        cout << ans << endl;
    }
}