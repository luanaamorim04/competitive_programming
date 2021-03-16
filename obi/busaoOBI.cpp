#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, l, o, d, c, x, nivel[1505];
vector<int> grafo[1505];
queue<int> fila;

int main()
{
    cin >> t >> l >> o >> d;
    for (int i = 1; i <= l; i++)
    {
        cin >> c;
        while (c--)
        {
            cin >> x;
            grafo[x].push_back(t + i);
            grafo[t + i].push_back(x);
        }
    }

    fila.push(o);
    
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();

        if (f == d)
        {
            cout << nivel[f]/2 << endl;
            break;
        }
        
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!nivel[v] && v != o)
            {
                nivel[v] = nivel[f] + 1;
                fila.push(v);
            }
        }
    }
}