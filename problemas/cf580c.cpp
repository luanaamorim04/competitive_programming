#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, cat[100009], a, b, ans;
vector<int> grafo[100009];
queue<par> fila;

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    fila.push(make_pair(1, 0));
    while (!fila.empty())
    {
        int u = fila.front().first, p = fila.front().second; fila.pop();

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            if (v != p)
            {
                if (cat[v]) cat[v] += cat[u];
                if (cat[v] <= m)
                fila.push(make_pair(v, u));
            }
        }

        if (grafo[u].size() == 1 && cat[u] <= m && u != 1)
            ans++;
    }

    cout << ans << endl;
}