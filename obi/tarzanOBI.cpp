#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, d, a, b, a1, a2, b1, b2, passou[1001];
pair<int, int> cipo[1001];
queue<int> fila;
vector<int> grafo[1001];

int main()
{_
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> cipo[i].first >> cipo[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a1 = cipo[i].first, b1 = cipo[i].second, a2 = cipo[j].first, b2 = cipo[j].second;
            a1 = (a1 - a2) * (a1 - a2);
            b1 = (b1 - b2) * (b1 - b2);
            double dist = sqrt(a1 + b1);
            if (dist <= d)
            {
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }

    fila.push(1);
    passou[1] = 1;
    while (!fila.empty())
    {
        n--;
        int f = fila.front(); fila.pop();
        for (int j = 0; j < grafo[f].size(); j++)
        {
            if (!passou[grafo[f][j]])
            {
                fila.push(grafo[f][j]);
                passou[grafo[f][j]] = 1;
            }
        }
    }

    cout << (n ? 'N' : 'S') << endl;
}