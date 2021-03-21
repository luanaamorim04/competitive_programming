#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#define mp make_pair
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

pair<int, int> v[200000], o[200000];
map<pair<int, int>, int> indexx, res;
stack<pair<int, int> > pilha;

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a > b;
}

int main()
{_
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        indexx[v[i]] = i + 1;
        o[i] = v[i];
    }

    // achar proximo maior
    sort(v, v + n);
    for (int i = 0; i < n; i++)
    {
        while (!pilha.empty() && v[i].second > pilha.top().second)
        {
            res[pilha.top()] = indexx[v[i]];
            pilha.pop();
        }
        pilha.push(v[i]);
    }

    while (!pilha.empty())
    {
        res[pilha.top()] = -1;
        pilha.pop();
    }

    // achar maior que veio antes
    sort(v, v + n, cmp);
    for (int i = 0; i < n; i++)
    {
        while (!pilha.empty() && v[i].second > pilha.top().second)
        {
            // diferenca entre a distancia da cidade que veio dps ate essa q ta checando agr
            int x = abs(o[res[pilha.top()] - 1].first - pilha.top().first); 
            // diferenca entre a distancia da cidade que veio antes ate essa q ta checando agr
            int y = abs(v[i].first - pilha.top().first);

            if (res[pilha.top()] == -1)
                res[pilha.top()] = indexx[v[i]];
            else if  (x > y)
                res[pilha.top()] = indexx[v[i]];
            else if (x == y && o[res[pilha.top()] - 1].second < v[i].second)
                res[pilha.top()] = indexx[v[i]];

            pilha.pop();
        }
        pilha.push(v[i]);
    }

    for (int i = 0; i < n; i++)
        cout << res[o[i]] << ' ';

    cout << endl;

}