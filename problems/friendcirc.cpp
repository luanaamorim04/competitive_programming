#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, tam[1000090], pai[1000090], k, a , b;
string x, y;
map<string, int> mapa;

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

int join(int a, int b)
{
    a = id(a), b = id(b);
    if (a == b) return tam[a];
    if (tam[a] > tam[b])
    {
        int tmp = a; a = b; b = tmp;
    }

    pai[a] = b;
    tam[b] += tam[a];
    return tam[b];
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        mapa.clear();
        k = 0;
        while (n--)
        {
            cin >> x >> y;
            if (!mapa[x])
            {
                mapa[x] = ++k;
                tam[k] = 1;
                pai[k] = k;
            } 
            if (!mapa[y])
            {
                mapa[y] = ++k;
                tam[k] = 1;
                pai[k] = k;
            } 

            a = mapa[x], b = mapa[y];

            cout << join(a, b) << endl;
        }
    }
}