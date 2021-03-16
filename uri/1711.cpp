#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e4 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, q, tamanho, s, cor[MAXN], ciclo[MAXN], dist[MAXN];
vector<par> grafo[MAXN], aresta, aux;
priority_queue<par, vector<par>, greater<par> > fila;

void dfs(int u, int p, int peso)
{
    cor[u] = 1;
    aresta.push_back(par(u, peso));
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i].first, w = grafo[u][i].second;
        if (v != p)
        {
            if (cor[v] == 1)
            {
                int sum = w;
                while (aresta.back().first != v)
                {
                    aux.push_back(aresta.back());
                    sum += aresta.back().second;
                    aresta.pop_back();
                }

                while (aux.size())
                {
                    aresta.push_back(aux.back());
                    ciclo[aux.back().first] = sum;
                    aux.pop_back();
                }

                ciclo[v] = sum;
            }   

            if (!cor[v]) dfs(v, u, w);
        }
    }
    cor[u] = 2;
    aresta.pop_back();
}

int solve()
{
    int ans = INF;
    fila.push(par(0, s));
    dist[s] = 0;
    while (!fila.empty())
    {
        int u = fila.top().second, d = fila.top().first; fila.pop();
        if (d > dist[u]) continue;
        if (ciclo[u] >= tamanho) ans = min(ans, 2*dist[u] + ciclo[u]);

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first, w = grafo[u][i].second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                fila.push(par(dist[v], v));
            }
        }
    }

    return (ans == INF ? -1 : ans);
}

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(par(b, c));
        grafo[b].push_back(par(a, c));
    }

    dfs(1, 0, 0);
    
    cin >> q;
    while (q--)
    {
        for (int i = 0; i <= n; i++) dist[i] = INF;
        cin >> s >> tamanho;
        cout << solve() << endl;
    }
}