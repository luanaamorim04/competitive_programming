#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <map> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, passou[101], cor[101];
vector<int> grafo[101], mapa[101];
queue<int> fila;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        fila.push(a);
        passou[a] = 1;
        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();

            for (int j = 0; j < grafo[f].size(); j++)
            {
                int v = grafo[f][j];
                if (!passou[v])
                {
                    passou[v] = 1;
                    fila.push(v);
                    mapa[v] = mapa[f];
                    mapa[v].push_back(f);
                }
            }
        }

        for (int j = 0; j < mapa[b].size(); j++)
        {
            cor[mapa[b][j]] = c;
        }

        cor[b] = c;

        for (int j = 1; j <= n; j++)
        {
            mapa[j].clear();
            passou[j] = 0;
        }
    }

    for (int j = 1; j <= n; j++)
        cout << cor[j] << ' ';

    cout << endl;
}