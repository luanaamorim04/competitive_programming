#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, pai[101], tam[101], teste;
vector<par> grafo;
map<par, int> peso;

int cmp(par a, par b)
{
    return peso[a] < peso[b];
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
    while (cin >> n >> m && n)
    {
        cout << "Teste " << ++teste << endl;
        grafo.clear();

        while (m--)
        {
            cin >> a >> b >> c;
            pai[a] = a; pai[b] = b;
            tam[a] = 1; tam[b] = 1;
            grafo.push_back(make_pair(a, b));
            peso[make_pair(a, b)] = c;
        }

        sort(grafo.begin(), grafo.end(), cmp);

        for (int i = 0; i < grafo.size(); i++)
        {
            a = grafo[i].first, b = grafo[i].second;
            if (id(a) == id(b)) continue;
            cout << min(a, b) << ' ' << max(a, b) << endl;
            a = id(a), b = id(b);
            join(a, b);
        }

        cout << endl;
    }
}