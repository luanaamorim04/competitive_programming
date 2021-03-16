#include <iostream>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, t, ok, mesas[1010], x;
queue<int> fila;
string linha;
vector<int> grafo[1010];

int main()
{_
    while (cin >> n && n)
    {
        ok = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            cin.ignore();
            getline(cin, linha);
            linha.push_back(' ');
            for (int i = 0; i < linha.size(); i++)
            {
                if (linha[i] == ' ')
                {
                    grafo[a].push_back(b);
                    grafo[b].push_back(a);
                    x = 1; b = 0;
                }
                else
                {
                    b = b * x + (linha[i] - '0');
                    x *= 10;
                }
            }
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

        cout << (ok ? "SIM" : "NAO") << endl;
    }
}