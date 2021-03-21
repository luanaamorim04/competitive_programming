#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define MAX 100009
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int l, s, q, a, p, m, t, x, y, res, f, g, passou[MAX], nivel[MAX], n, ans;
pair<int, int> local[MAX];
vector<int> grafo[1000009];
queue<int> fila;

int main()
{_
    cin >> l >> s >> q >> a;
    for (int i = 0; i < s; i++)
    {
        cin >> p >> m >> t;
        local[p] = make_pair(m, t);
    }
    for (int i = 0; i < a; i++)
    {
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        ans = 0;
        n = MAX;
        fila.push(x); passou[x] = i; nivel[x] = 0;

        while (!fila.empty())
        {
            f = fila.front(); fila.pop();
            if (local[f].first && nivel[f] <= n)
            {
                n = nivel[f];
                local[ans] > local[f] ? ans = ans : ans = f;
            }
            else if (nivel[f] > n)
            {
                while (!fila.empty()) fila.pop();
                break;
            }
            
            for (int j = 0; j < grafo[f].size(); j++)
            {
                g = grafo[f][j];
                nivel[g] = nivel[f] + 1;
                if (passou[g] != i)
                {
                    passou[g] = i;
                    fila.push(g);
                }
            }
        }

        if (ans) cout << ans << endl;
        else cout << "Noic\n";
    }
}
