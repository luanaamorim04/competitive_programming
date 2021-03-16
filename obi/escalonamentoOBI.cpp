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

int n, m, a, b, grau[500009];
vector<int> grafo[500009], ordem;
priority_queue<int, vector<int>, greater<int> > fila;

int main()
{_
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grau[b]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (!grau[i]) fila.push(i);
    }

    while (!fila.empty())
    {
        int f = fila.top(); fila.pop();
        ordem.push_back(f);

        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            grau[v]--;
            if (!grau[v]) fila.push(v);
        }
    }

    if (ordem.size() < n)
    {
        cout << "*\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << ordem[i] << endl;
    }
}