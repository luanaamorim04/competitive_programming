#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define MAXN 1003
#define sz(x) (int) x.size()

using namespace std;

int pai[MAXN], cand[MAXN][MAXN], n, flag[MAXN], a, b, m, aparece[MAXN], maior, pai1[MAXN];
vector<int> grafo[MAXN], level[MAXN], depois[MAXN];
vector<pair<int, int> > resp;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int raiz = 0;
        for (int i = 1; i <= n; i++)
            raiz ^= i;

        pai1[raiz] = pai[raiz] = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            raiz ^= a;
            pai1[a] = b;
            grafo[b].push_back(a);
        }

        cin >> m;
        for (int i = 1; i < m; i++)
        {
            cin >> a >> b;
            depois[b].push_back(a);
            pai[a] = b;
            aparece[a] = aparece[b] = 1;
        }

        queue<pair<int, int> > fila;
        fila.push({raiz, 0});
        while (!fila.empty())
        {
            auto[u, k] = fila.front(); fila.pop();
            maior = k;
            for (int v : grafo[u])
                fila.push({v, k+1});
            level[k].push_back(u);
        }

        for (int nivel = maior; nivel >= 0; nivel--)
        {
            sort(level[nivel].begin(), level[nivel].end());
            for (int i = 0; i < sz(level[nivel]); i++) //quais candidatos
            {
                int u = level[nivel][i];
                if (aparece[u])
                {
                    cand[u][u] = 1;
                    continue;
                }

                for (int j = i + 1; j < sz(level[nivel]); j++) // checar se pode
                {
                    int pode = 1;
                    int v = level[nivel][j];
                    if (!aparece[v]) continue;
                
                    for (int k1 : grafo[u])
                    {
                        int ok = 0;
                        for (int k2 : depois[v])
                            ok |= (cand[k1][k2]);

                        pode &= ok;
                    }

                    cand[u][v] = pode;
                }
            }
        }

        fila.push({raiz, raiz});
        while (!fila.empty())
        {
            auto[u, p] = fila.front(); fila.pop();
            for (int v : grafo[u])
            {
                int i;
                for (i = 1; i <= n; i++)
                {
                    if (cand[v][i] && pai[i] == p)
                    {
                        if (v != i) resp.push_back({v, i});
                        break;
                    }
                }   
                fila.push({v, i});  
            }
        }

        cout << sz(resp) << endl;
        for (auto[a, b] : resp)
            cout << a << ' ' << b << endl;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cand[i][j] = 0;

            grafo[i].clear();
            depois[i].clear();
            level[i-1].clear();
            aparece[i] = flag[i] = 0;
        }

        resp.clear();
    }
}