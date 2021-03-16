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

int n_linhas, n, nivel[10009], t;
string buff, lista[10009], nome;
map<string, int> id;
vector<int> grafo[10009], add;
queue<int> fila;

int cmp(string a, string b)
{
    string c, d;

    for (int j = 3; j < a.size(); j++)
        c += a[j];

    for (int j = 3; j < b.size(); j++)
       d += b[j];

    if (c != d) return c < d;
    return a[0] < b[0];
}

int main()
{_
    while (cin >> n_linhas && n_linhas)
    {
        for (int i = 0; i <= 100; i++)
        {
            nivel[i] = 0;
            grafo[i].clear();
        }
        n = 0;
        id.clear();
        getline(cin, buff);
        while (n_linhas--)
        {
            add.clear();
            getline(cin, buff);
            buff[buff.size() - 1] = ',';
            for (int i = 0; i < buff.size(); i++)
            {
                if (buff[i] == ',')
                {
                    if (!id[nome])
                    {
                        lista[n++] = nome;
                        id[nome] = n;
                    }

                    add.push_back(id[nome]);
                    nome = "";
                    ++i;
                    continue;
                }

                nome += buff[i];
            }

            for (int i = 0; i < add.size(); i++)
            {
                for (int j = 0; j < add.size(); j++)
                {
                    if (i == j) continue;
                    grafo[add[i]].push_back(add[j]);
                }
            }
        }

        fila.push(id["P. Erdos"]);
        nivel[id["P. Erdos"]] = 1;
        while (!fila.empty())
        {
            int f = fila.front(); fila.pop();

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

        sort(lista, lista+n, cmp);

        cout << "Teste " << ++t << endl;

        for (int i = 0; i < n; i++)
        {
            int x = id[lista[i]];
            if (lista[i] == "P. Erdos") continue;
            cout << lista[i] << ": ";
            if (nivel[x] == 0) cout << "infinito\n";
            else cout << nivel[x] - 1 << endl;
        }

        cout << endl;
    }
}