#include <iostream>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, p, t1, t2, passou[25], foward[25], caso;
string a1, a2, a3, nome, ans[25];
vector<int> grafo[25];
queue<int> fila;

int main()
{_
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            while (cin >> m && m)
            {
                grafo[i].push_back(m);
            }
        }

        while (cin >> p && p)
        {
            cin >> t1 >> t2 >> a1 >> a2 >> a3;
            fila.push(p);
            passou[p] = 1;

            while (!fila.empty())
            {
                int f = fila.front(); fila.pop();

                for (int i = 0; i < grafo[f].size(); i++)
                {
                    int g = grafo[f][i];
                    foward[f]++;
                    if (passou[g] != 1)
                    {
                        passou[g] = 1;
                        fila.push(g);
                    }
                }
            }

            for (int i = 1; i <= n; i++)
            {
                passou[i] = 0;
                if (foward[i] < t1)
                {
                    ans[i] += a1;
                    ans[i] += ' ';
                }
                else if (foward[i] < t2)
                {
                    ans[i] += a2;
                    ans[i] += ' ';
                }
                else
                {
                    ans[i] += a3;
                    ans[i] += ' ';
                }

                foward[i] = 0;
            }
        }

        if (caso) cout << endl;

        for (int i = 1; i <= n; i++)
        {
            if (i < n) cout << endl;
            cin >> nome;
            cout << nome << ": " << ans[i];
            ans[i] = "";
            grafo[i].clear();
            foward[i] = 0;
            passou[i] = 0;
        }

        caso = 1;
    }
}