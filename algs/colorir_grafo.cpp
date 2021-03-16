#include <iostream>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, ok, passou[1010];
queue<int> fila;
vector<int> grafo[1010];

int main()
{_
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (passou[i]) continue;
        
        fila.push(i);
        passou[i] = 1;
        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();
            for (int j = 0; j < grafo[f].size(); j++)
            {
                int g = grafo[f][j];
            
                if (!passou[g])
                {
                    passou[g] = -passou[f];
                    fila.push(g);
                }
                else if (passou[g] == passou[f])
                {
                    ok = 1;
                }
            }
        }
    }

    cout << (!ok ? "sim" : "nao") << endl;
}