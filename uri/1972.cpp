#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 9999999
#define par pair<int, pair<int, int> >
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[505][505], a, b, c, d, soma[505][505];
priority_queue<par, vector<par>, greater<par> > fila;
char C;

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> C;
            soma[i][j] = INF;
            tab[i][j] = 0;

            if (C == '#') tab[i][j] = -1;
            else if (C == 'H') a = i, b = j;
            else if (C == 'E') c = i, d = j;
            else if (C != '.') tab[i][j] = C - '0';
        }
    }
        

    fila.push(make_pair(0, make_pair(a, b)));
    soma[a][b] = 0;

    while (!fila.empty())
    {
        int d = fila.top().first;
        a = fila.top().second.first, b  = fila.top().second.second; fila.pop();

        if (a < 1 || b < 1 || a > n || b > m) continue;
        if (d > soma[a][b]) continue;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i && j) continue;
                int w = tab[a + i][b + j];
                if (w == -1) continue;
                if (soma[a + i][b + j] > soma[a][b] + w)
                {
                    soma[a + i][b + j] = soma[a][b] + w;
                    fila.push(make_pair(soma[a + i][b + j], make_pair(a + i, b + j)));
                }
            }
        }
    }

    if (soma[c][d] != INF) cout << soma[c][d] << endl;
    else cout << "ARTSKJID\n";
}