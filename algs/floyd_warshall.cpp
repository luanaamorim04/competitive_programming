/*
    -> complexidade cúbica
    -> trabalha com matriz de adj
    -> guardar em dist[i][j] a distancia minima entre i e j 
    -> no início a distância entre qualquer vértice e si mesmo é 0
    e a distância entre qualquer vértice e outro vértice é INF
    -> caminho minimo entre todos os pares de vertices
    -> minimax
    -> fecho transitivo
    -> scc componente fortemente conexo
    -> ciclo mais barato
*/

#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, dist[109][109], a, b, c;

int main()
{_
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            dist[i][i] = 0;
        }

    while (m--)
    {
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[k][j] + dist[i][k])
                    dist[i][j] = dist[k][j] + dist[i][k];

    cout << dist[1][n] << endl;
}