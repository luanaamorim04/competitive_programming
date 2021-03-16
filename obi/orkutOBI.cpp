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

int n, m, grau[32], t;
string s, a, nomes[32];
map<string, int> mapa;
vector<int> grafo[32], ans;
queue<int> fila;

int kahn()
{
    for (int i = 1; i <= n; i++)
    {
        if (!grau[i]) fila.push(i);
    }

    while (!fila.empty())
    {
        int f = fila.front(); fila.pop();
        ans.push_back(f);
        for (int i = 0; i < grafo[f].size(); i++)
        {
            int v = grafo[f][i];
            grau[v]--;
            if (!grau[v]) fila.push(v);
        }
    }

    return ans.size() == n;
}

int main()
{_
    while (cin >> n && n)
    {
        ans.clear();
        cout << "Teste " << ++t << endl;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            mapa[s] = i;
            nomes[i] = s;
            grafo[i].clear();
            grau[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> s >> m;
            if (!m) continue;
            while (m--)
            {
                cin >> a;
                grau[mapa[s]]++;
                grafo[mapa[a]].push_back(mapa[s]);
            }
        }

        if (kahn())
        {
            for (int i = 0; i < n; i++)
                cout << nomes[ans[i]] << ' ';
            cout << endl;
        }
        else
        {
            cout << "impossivel\n";
        }
        cout << endl;
    }
}