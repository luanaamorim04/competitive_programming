#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x, y, a, b, c, nivel[10009];
vector<par> grafo[10009];
queue<int> fila;

int main()
{_
    cin >> n >> x >> y;
    n--;
    while (n--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }

    fila.push(x);
    nivel[x] = 1;

    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();

        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i].first, w = grafo[f][i].second;
            if (!nivel[v])
            {
                fila.push(v);
                nivel[v] = nivel[f] + w;
            }
        }
    }

    cout << nivel[y] - 1 << endl;
}