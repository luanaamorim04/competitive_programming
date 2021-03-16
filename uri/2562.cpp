#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, passou[1009], a, b, res, e, t;
queue<int> fila;

int main()
{_
    while (cin >> n >> m)
    { 
        vector<int> grafo[1009];
        t++;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        cin >> e;
        res = 1;

        fila.push(e);
        passou[e] = t;
        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();
            for (int j = 0; j < grafo[f].size(); j++)
            {
                if (passou[grafo[f][j]] != t)
                {
                    fila.push(grafo[f][j]);
                    passou[grafo[f][j]] = t;
                    res++;
                }
            }
        }

        cout << res << endl;
    }
}