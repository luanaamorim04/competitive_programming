#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, p[22], passou[22], ok;
vector<par> grafo[22];
queue<int> fila;

int main()
{_
    while (cin >> n >> m && n)
    {
        ok = 1;
        for (int i = 1; i <= n; i++) 
        {
            cin >> p[i];
            passou[i] = 0;
            grafo[i].clear();
        }

        while (m--)
        {
            cin >> a >> b >> c;
            grafo[a].push_back(make_pair(b, c));
        }

        for (int i = 1; i <= n; i++)
        {
            if (!passou[i])
            {
                fila.push(i);
                passou[i] = 1;
                while (!fila.empty())
                {
                    int u = fila.front(); fila.pop();
                    for (int i = 0; i < grafo[u].size(); i++)
                    {
                        int v = grafo[u][i].first, w = grafo[u][i].second;
                        if (!passou[u])
                        {
                            passou[v] = 1;
                            fila.push(v);
                        }

                        p[v] += w;
                        p[u] -= w;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (p[i] < 0) ok = 0;
        }

        cout << (ok ? 'S' : 'N') << endl;
    }
}