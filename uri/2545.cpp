#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, grau[1009], nivel[1009];
vector<int> grafo[1009];
queue<int> fila;

int kahn(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!grau[i]) fila.push(i);
    }

    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        ans = max(ans, nivel[f]);
        n--;
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            grau[v]--;
            if (!grau[v]) fila.push(v);
            nivel[v] = nivel[f] + 1;
        }
    }

    return (n ? -1 : ans + 1);
}

int main()
{_
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
            grafo[i].clear();

        for (int i = 1; i <= n; i++)
        {
            nivel[i] = 0;
            cin >> m;
            grau[i] = m;
            while (m--)
            {
                cin >> a;
                grafo[a].push_back(i);
            }
        }

        cout << kahn(n) << endl;
    }
}