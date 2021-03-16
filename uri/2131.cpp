#include <iostream>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, t, ok, mesas[1010];
queue<int> fila;
vector<int> grafo[1010];

int main()
{_
    while (cin >> n >> m)
    {
        ok = 1;
        cout << "Instancia " << ++t << endl;
        
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!mesas[i])
            {    
                fila.push(i);
                mesas[i] = 1;
                while (!fila.empty())
                {
                    int f = fila.front(); fila.pop();
                    for (int j = 0; j < grafo[f].size(); j++)
                    {
                        int g = grafo[f][j];
                    
                        if (!mesas[g])
                        {
                            mesas[g] = -mesas[f];
                            fila.push(g);
                        }
                        else if (mesas[g] == mesas[f])
                        {
                            ok = 0;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            mesas[i] = 0;
            grafo[i].clear();
        }

        cout << (ok ? "sim" : "nao") << endl << endl;
    }
}