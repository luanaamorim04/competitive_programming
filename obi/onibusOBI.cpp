#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x, y, a, b, nivel[10009];
vector<int> grafo[10009];
queue<int> fila;

int main()
{_
    cin >> n >> x >> y;
    n--;
    while (n--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    fila.push(x);
    nivel[x] = 1;

    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();

        if (f == y)
        {
            cout << nivel[f] - 1<< endl;
            return 0;
        }

        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!nivel[v])
            {
                fila.push(v);
                nivel[v] = nivel[f] + 1;
            }
        }
    }
}