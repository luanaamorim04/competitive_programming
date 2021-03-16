#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, M, I, idade[505], a, b, id[505], mais_novo, passou[505];
char c;
vector<int> grafo[505];
queue<int> fila;

int FIND(int x, int y)
{
    if (id[x] == y) return x;
    return FIND(id[x], y);
}

int main()
{_
    cin >> N >> M >> I;
    for (int i = 1; i <= N; i++)
    {
        id[i] = i;
        cin >> idade[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        grafo[b].push_back(a); 
    }

    for (int i = 1; i <= I; i++)
    {
        cin >> c;
        if (c == 'T')
        {
            cin >> a >> b;
            swap(id[FIND(a, a)], id[FIND(b, b)]);
        }
        else
        {
            cin >> a;
            int x = FIND(a, a);
            fila.push(x);
            passou[x] = i;
            mais_novo = 999;
            while (!fila.empty())
            {
                int f = fila.front(); fila.pop();
                
                for (int j = 0; j < grafo[f].size(); j++)
                {
                    int v = grafo[f][j];
                    if (passou[v] != i)
                    {
                        fila.push(v);
                        passou[v] = i;
                        mais_novo = min(mais_novo, idade[id[v]]);
                    }
                }
            }

            if (mais_novo != 999) cout << mais_novo << endl;
            else cout << '*' << endl;
        }
    }
}