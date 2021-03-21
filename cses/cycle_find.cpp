#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll dist[1<<20];
int n, m, pai[1<<20], x, y, a, b, c;
vector<par> grafo[1<<20];

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(par(b, c));
    }

    for (int i = 0; i < n; i++)
    {
        x = 0;
        for (int u = 1; u <= n; u++)
        {
            for (int k = 0; k < grafo[u].size(); k++)
            {
                int v = grafo[u][k].first;
                if (dist[u] > dist[v] + grafo[u][k].second) 
                {
                    x = u;
                    pai[u] = v;
                    dist[u] = dist[v] + grafo[u][k].second;
                }
            }
        }
    }

    if (!x)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        x = pai[x];
    y = pai[x];
    cout << x << ' ';
    while (x != y)
    {
        cout << y << ' ';
        y = pai[y];
    }
    cout << x << endl;
}