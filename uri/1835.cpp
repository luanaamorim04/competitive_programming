#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, passou[50009], a, b, res, t, T;
vector<int> grafo[50009];

void dfs(int x)
{
    passou[x] = T;
    for (int i = 0; i < grafo[x].size(); i++)
    {
        if (passou[grafo[x][i]] != T)
        {
            passou[grafo[x][i]] = T;
            dfs(grafo[x][i]);
        }
    }

    grafo[x].clear();
}

int main()
{
    cin >> t;
    for (T = 1; T <= t; T++)
    {    
        res = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (passou[i] != T)
            {
                res++;
                dfs(i);
            }
        }

        cout << "Caso #" << T << ':';

        if (res == 1) cout << " a promessa foi cumprida\n";
        else cout << " ainda falta(m) " << res - 1 << " estrada(s)\n";
    }
}
