#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, pai[450], tam[450], k, ans;
vector<pair<int, int> > tirar, botar;
map<pair<int, int>, int> mapa;

int cmp(pair<int, int> a, pair<int, int> b)
{
    return mapa[a] > mapa[b];
}

int cmp2(pair<int, int> a, pair<int, int> b)
{
    return mapa[a] < mapa[b];
}

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (a == b) return;
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pai[i] = i;
        tam[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
            {
                cin >> k;
                (k ? tirar : botar).push_back(make_pair(i, j));
            }
            else
            {
                cin >> k;
                mapa[make_pair(j, i)] = k;
            }
        }       
    }

    sort(tirar.begin(), tirar.end(), cmp);
    sort(botar.begin(), botar.end(), cmp2);

    for (int i = 0; i < tirar.size(); i++)
    {
        int a = id(tirar[i].first), b = id(tirar[i].second);
        if (a == b) ans += mapa[tirar[i]];
        join(a, b);
    }

    for (int i = 0; i < botar.size(); i++)
    {
        int a = id(botar[i].first), b = id(botar[i].second);
        if (a != b) ans += mapa[botar[i]];
        join(a, b);
    }

    cout << ans << endl;
}