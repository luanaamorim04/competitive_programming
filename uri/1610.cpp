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

int t, n, m, a, b, grau[10009];
vector<int> grafo[10009];
queue<int> fila;

int kahn(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!grau[i]) fila.push(i);
    }

    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        n--;
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            grau[v]--;
            if (!grau[v]) fila.push(v);
        }
    }

    return n;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            grau[i] = 0;
            grafo[i].clear();
        }

        while (m--)
        {
            cin >> a >> b;
            grau[a]++;
            grafo[b].push_back(a);
        }

        if (kahn(n)) cout << "SIM\n";
        else cout << "NAO\n";
    }
}