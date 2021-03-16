#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, j, nivel[10009], maxn;
double total[10009], foi[10009], media;
vector<int> grafo[10009];
queue<int> fila;

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> j;
        grafo[j].push_back(i);
        grafo[i].push_back(j);
    }

    fila.push(0);
    nivel[0] = 1;
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        total[nivel[f]]++;
        maxn = max(maxn, nivel[f]);
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (!nivel[v])
            {
                nivel[v] = nivel[f] + 1;
                fila.push(v);
            }
        }
    }

    while (m--)
    {
        cin >> j;
        foi[nivel[j]]++;
    }

    for (int i = 2; i <= maxn; i++)
    {
        if (foi[i] == 0)
        {
            cout << fixed << setprecision(2) << foi[i] << ' ';
            continue;
        }
        media = (100 * foi[i]) / total[i];
        cout << fixed << setprecision(2) << media << ' ';
    }

    cout << endl;
}