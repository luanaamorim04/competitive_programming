#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, grau[100001], nivel[100001];
vector<int> grafo[100001], centro;

void bfs()
{
    queue<pair<int, int> > fila;
    fila.push(make_pair(1, 0));
    while (!fila.empty())
    {
        int u = fila.front().first, p = fila.front().second; fila.pop();
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            if (p != v) 
            {
                fila.push(make_pair(v, u));
                nivel[v] = nivel[u] + 1;
            }
        }
    }
}

int top_sort()
{
    queue<int> fila;
    for (int i = 1; i <= n; i++)
    {
        if (grau[i] == 1) fila.push(i);
    }

    int N = n;

    while (N > 2)
    {
        int u = fila.front(); fila.pop();
        cout << u << endl;
        grau[u]--;
        N--;
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            grau[v]--;
            if (grau[v] == 1) fila.push(v);
        }
    }

    int dist = 0, resp;
    while (!fila.empty())
    {
        if (nivel[fila.front()] > dist) dist = nivel[fila.front()], resp = fila.front();
        fila.pop();
    }

    return resp;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        grau[a]++;
        grau[b]++;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    bfs();
    cout << top_sort() << endl;
}