#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, pai[505], tam[505], a, b, c, ans, l;
map<pair<int, int>, int > mapa;
vector<pair<int, int> > v;

int cmp(pair<int, int> a, pair<int, int> b)
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
    if (tam[a] > tam[b]) swap(a, b);
    pai[a] = b;
    tam[b] += tam[a];
}

int main()
{
    cin >> n >> m >> l;

    for (int i = 1; i <= n; i++)
    {
        pai[i] = i;
        tam[i] = 1;
    }
    while (m--)
    {
        cin >> a >> b >> c;
        mapa[make_pair(a, b)] = c;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        a = id(v[i].first), b = id(v[i].second);
        if (a == b) continue;
        ans += mapa[v[i]];
        join(a, b);
    }

    cout << ans*2 << endl;
}