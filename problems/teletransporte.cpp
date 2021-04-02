#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x, nivel[1000009];
vector<int> grafo[1000009];
queue<int> fila;

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            grafo[x].push_back(n + i);
            grafo[n + i].push_back(x);
        }
    }

    fila.push(1);
    
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();

        if (f == n)
        {
            cout << nivel[f]/2 + 1 << endl;
            return 0;
        }
        
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!nivel[v] && v != 1)
            {
                nivel[v] = nivel[f] + 1;
                fila.push(v);
            }
        }
    }

    cout << -1 << endl;
}