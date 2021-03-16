#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[505];
int n, m, ini, fim, dist[505][3], a, b, c, p[505][505];
queue<par> fila;

int main()
{_
    cin >> n >> ini >> fim >> m;

    for (int i = 0; i <= n; i++) 
    {
        dist[i][0] = INF; dist[i][1] = INF; dist[i][2] = INF;
    }

    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(b);
        if (p[a][b]) p[a][b] = 2;
        else c ? p[a][b] = 1 : p[a][b] = -1;
    }

    dist[ini][0] = 0;
    fila.push(make_pair(0, ini));

    while (!fila.empty())
    {
        int tempo = fila.front().first, u = fila.front().second; fila.pop();
    
        if (u == fim) break;
        
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            if (dist[v][(tempo + 1) % 3] <= dist[u][tempo % 3] + 1) continue;
            if (tempo % 3 == 0 && p[u][v] != -1)
            {   
                dist[v][(tempo + 1) % 3] = dist[u][tempo % 3] + 1;
                fila.push(make_pair(dist[v][(tempo + 1) % 3], v));
            }
            else if (tempo % 3 && p[u][v] != 1)
            {
                dist[v][(tempo + 1) % 3] = dist[u][tempo % 3] + 1;
                fila.push(make_pair(dist[v][(tempo + 1) % 3], v));
            }
        }
    }

    int ans = min(dist[fim][0], min(dist[fim][1], dist[fim][2]));
    if (ans != INF) cout << ans << endl;
    else cout << '*' << endl;
}