#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, passou[1001], c;
queue<int> fila;
vector<int> grafo[1001];

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> k;
            if (k)
            {
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!passou[i])
        {
            c++;
            fila.push(i);
            passou[i] = 1;
            while (!fila.empty())
            {
                int f = fila.front(); fila.pop();
                for (int i = 0; i < grafo[f].size(); i++)
                {
                    int v = grafo[f][i];
                    if (!passou[v])
                    {
                        fila.push(v);
                        passou[v] = 1;
                    }
                }
            }
        }
    }

    cout << (c <= 2 && n >= 2 ? "Bazinga!\n" : "Fail!\n");
}