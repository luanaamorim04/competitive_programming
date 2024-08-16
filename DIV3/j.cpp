#include <bits/stdc++.h>
#define MAXN 53
#define INF 1e9
#define ii pair<int, int>
#define iii tuple<int, int, int>


using namespace std;

char tab[MAXN][MAXN], ini[MAXN][MAXN];
int n, m, dist[MAXN][MAXN], caso;
queue<ii> fila;
vector<tuple<int, int, int, int> > resp;
priority_queue<iii> pq;
ii entrada, saida, pai[MAXN][MAXN];

void inter(int caso)
{
    memset(dist, -1, sizeof dist);
    if (caso == 1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (ini[i][j] == '*' && tab[i][j] == '*')
                {
                    fila.push({i, j});
                    dist[i][j] = 0;
                }
            }
    }
    else
    {
        fila.push(entrada);
        dist[entrada.first][entrada.second] = 0;
    }

    priority_queue<iii> bota;
    while (!fila.empty())
    {
        auto[a, b] = fila.front(); fila.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if (i && j) continue; 
                if (dist[a+i][b+j] == -1 && tab[a+i][b+j] == '*') 
                {
                    dist[a+i][b+j] = dist[a][b] + 1;
                    fila.push({a+i, b+j});
					bota.push({-dist[a+i][b+j], a+i, b+j});
                }
            }
    }

    while (!bota.empty())
    {
        auto[x, a, b] = pq.top(); pq.pop();
        auto[y, c, d] = bota.top(); bota.pop();
        resp.push_back({a, b, c, d});
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++)
            tab[i][j] = ini[i][j] = 'X';

    memset(dist, -1, sizeof dist);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ini[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == '*')
            {
                dist[i][j] = 0;
                if (ini[i][j] == '*') caso = 1;
                fila.push({i, j}); 
            }
        }


    //bfs final -> ini
    while (!fila.empty())
    {
        auto[a, b] = fila.front(); fila.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if (i && j) continue; 
                if (dist[a+i][b+j] == -1 && tab[a+i][b+j] != 'X') 
                {
                    pai[a+i][b+j] = {a, b};
                    dist[a+i][b+j] = dist[a][b] + 1;
                    fila.push({a+i, b+j});
                }
            }
    }

    int menor = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ini[i][j] == '*' && menor > dist[i][j])
            {
                menor = dist[i][j];
                saida = {i, j};
            }
        }
    }

    if (menor == -1)
    {
        cout << "NO" << endl;
        return 0;
    }

    memset(dist, -1, sizeof dist);

    // //bfs ini -> final
    fila.push(saida);
    dist[saida.first][saida.second] = 0;
    while (!fila.empty())
    {
        auto[a, b] = fila.front(); fila.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if (i && j) continue; 
                if (dist[a+i][b+j] == -1 && ini[a+i][b+j] == '*') 
                {
                    dist[a+i][b+j] = dist[a][b] + 1;
                    fila.push({a+i, b+j});
                }
            }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ini[i][j] == '*' && tab[i][j] != '*')
                pq.push({dist[i][j], i, j});
        }
    }

    if (caso == 1)
    {
        inter(1);
        cout << "YES" << endl;
        cout << resp.size() << endl;
        for (auto [a, b, c, d] : resp)
        {
            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        }
        return 0;
    }

    ii curr = saida;
    int idx = 0;
    while (tab[curr.first][curr.second] != '*')
    {
        curr = pai[curr.first][curr.second];
        auto[w, a, b] = pq.top(); pq.pop();
        resp.push_back({a, b, curr.first, curr.second});
        pq.push({--idx, curr.first, curr.second});
    }

    entrada = curr;

    if (resp.size() > 10000) return 1;

    inter(0);
    cout << "YES" << endl;
    cout << resp.size() << endl;
    for (auto [a, b, c, d] : resp)
    {
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
    return 0;
}

