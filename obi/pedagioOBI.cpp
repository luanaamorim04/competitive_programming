#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, l, p, a, b, passou[101], teste;
vector<int> grafo[101], ans;
queue<int> fila;

int main()
{_
    while (cin >> n >> m >> l >> p && n)
    {
        cout << "Teste " << ++teste << endl;
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            grafo[i].clear();
            passou[i] = -1;
        }
        while (m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        fila.push(l);
        passou[l] = 0;
        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();
            if (passou[f] <= p && f != l)
                ans.push_back(f);

            for (int i = 0; i < grafo[f].size(); i++)
            {
                int v = grafo[f][i];
                if (passou[v] == -1)
                {   
                    passou[v] = passou[f] + 1;
                    fila.push(v);
                }
            }
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';

        cout << "\n\n";
    }
}