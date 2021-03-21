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

int n, m, a, b, grau[10009], mau[10009], bom[10009], atual;
vector<int> grafo[10009], ordem;
priority_queue<par> fila;

int cmp(int a, int b)
{
    return bom[a] > bom[b];
}

string kahn(int n)
{
    for (int i = 1; i <= n; i++)
    {
        sort(grafo[i].begin(), grafo[i].end(), cmp);
        if (!grau[ordem[i - 1]] && mau[ordem[i - 1]] < atual) 
        {
            fila.push(make_pair(bom[ordem[i - 1], ordem[i - 1]));
            atual += bom[ordem[i - 1]];
        }
    }

    while (!fila.empty())
    {
        int f = fila.top().first; fila.pop();
        atual += bom[f];
        n--;
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            grau[v]--;
            if (!grau[v] && mau[v] < atual)
            {
                fila.push(make_pair(bom[v], v));
            } 
        }
    }

    return (n ? "impossivel\n" : "possivel\n");
}

int main()
{_
    while (cin >> n >> m >> atual && (n || m || atual))
    {
        ordem.clear();
        for (int i = 1; i <= n; i++)
        {
            grafo[i].clear();
            grau[i] = 0;
            cin >> mau[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> bom[i];
            ordem.push_back(i);
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            grau[b]++;
            grafo[a].push_back(b);
        }

        sort(ordem.begin(), ordem.end(), cmp);

        cout << kahn(n);
    }
}