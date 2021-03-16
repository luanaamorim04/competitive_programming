#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define MAX 100009
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, tam[MAX], ok, k;
vector<int> grafo[MAX];
queue<int> fila;

void dfs(int x)
{
    for (int i = 0; i < grafo[x].size(); i++)
    {
        int v = grafo[x][i];
        dfs(v);
        tam[x] += tam[v];
    }
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tam[i] = 1;
        cin >> a >> b;
        grafo[b].push_back(a);
    }

    dfs(0);

    fila.push(0);
    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            if (i == 0) k = tam[v];
            else if (tam[v] != k) ok = 1;
            fila.push(v);
        }
    }

    cout << (ok ? "mal" : "bem") << endl;
}
