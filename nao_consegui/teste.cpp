#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, nivel[100000], ideal[100000];
vector<int> grafo[100000];
queue<par> fila;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        grafo[b].push_back(a);
    }

    fila.push(make_pair(1, 0));
    nivel[0] = 1;
    while (!fila.empty())
    {
        int f = fila.front().second, t = fila.front().first; fila.pop();
        int tamanho = grafo[f].size() ? grafo[f].size() : -1;


        for (int i = 0; i < tamanho; i++)
        {
            int v = grafo[f][i];
            if (!nivel[v])
            {
                nivel[v] = nivel[f] + 1;
                fila.push(v);
            }
        }
    }

    cout << "bem" << endl;
}