#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <cstring>
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

par p;
int n, m, nivel[1001][1001], fogo[1001][1001], t, ok;
char tab[1001][1001];

int pode(int a, int b)
{
    if (a < 0 || b < 0 || a == n || b == m) return 0;
    if (nivel[a][b] || tab[a][b] == '#') return 0;
    return 1;
}   

int main()
{_
    cin >> t;
    while (t--)
    {
        queue<par> fila;
        cin >> m >> n;  
        ok = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> tab[i][j];
                nivel[i][j] = 0;
                if (tab[i][j] == '*') 
                {
                    fila.push(par(i, j));
                    nivel[i][j] = 1;
                }
                else if (tab[i][j] == '@') p = par(i, j);
                fogo[i][j] = INF;
            }

        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop();
            fogo[a][b] = nivel[a][b];
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                    if (!pode(a + i, b + j) || (i && j)) continue;
                    nivel[a + i][b + j] = nivel[a][b] + 1;
                    fila.push(par(a + i, b + j));
                }
        }

        memset(nivel, 0, sizeof(nivel));

        fila.push(p);
        nivel[p.first][p.second] = 1;
        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop();
            if (nivel[a][b] >= fogo[a][b]) continue;
            if (a == 0 || b == 0 || a == n - 1 || b == m - 1) 
            {
                cout << nivel[a][b] << endl;
                ok = 1;
                break; 
            }
            
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                    if (!pode(a + i, b + j) || (i && j)) continue;
                    nivel[a + i][b + j] = nivel[a][b] + 1;
                    fila.push(par(a + i, b + j));
                }
        }

        if (!ok) cout << "IMPOSSIBLE" << endl;
    }
}