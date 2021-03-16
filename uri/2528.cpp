#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, r, e, passou[1009], t;
queue<int> fila;
vector<int> grafo[1009];

int main()
{_
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
        {
            grafo[i].clear();
            passou[i] = 0;
        }
        while(m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        cin >> c >> r >> e;

        fila.push(c);
        passou[c] = 1;

        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();
            if (f == r)
            {
                cout << passou[f] - 1 << endl;
            }

            for (int i = 0; i < grafo[f].size(); i++)
            {
                int v = grafo[f][i];
                if (!passou[v] && v != e)
                {
                    fila.push(v);
                    passou[v] = passou[f] + 1;
                }
            }
        }
    }   
}