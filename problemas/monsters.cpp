#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

queue<par> fila;
int nivel[1001][1001], n, m, x, y, p[1001][1001];
char tab[1001][1001], last[1001][1001];

int pode(int a, int b)
{
    return (a >= 0 && b >= 0 && a < n && b < m && tab[a][b] != '#');
}

void resp(int a, int b)
{
    if (last[a][b] == 'U') resp(a + 1, b);
    else if (last[a][b] == 'D') resp(a - 1, b);
    else if (last[a][b] == 'L') resp(a, b + 1);
    else if (last[a][b] == 'R') resp(a, b - 1);
    if (last[a][b] != 'K') cout << last[a][b];
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            nivel[i][j] = INF;
            last[i][j] = 'K';
            if (tab[i][j] == 'M') fila.push(par(i, j)), nivel[i][j] = 1;
            if (tab[i][j] == 'A') x = i, y = j;
        }
    }

    while (!fila.empty())
    {
        int a = fila.front().first, b = fila.front().second; fila.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i && j) || !pode(a + i, b + j) || nivel[a + i][b + j] != INF) continue;
                fila.push(par(a + i, b + j));
                nivel[a + i][b + j] = nivel[a][b] + 1;
            }
        }
    }

    fila.push(par(x, y));
    p[x][y] = 1;
    while (!fila.empty())
    {
        int a = fila.front().first, b = fila.front().second; fila.pop();
        if (p[a][b] >= nivel[a][b]) continue;
        if (a == n - 1 || !a || !b || b == m - 1) 
        {
            cout << "YES" << endl;
            cout << p[a][b] - 1 << endl;
            resp(a, b);
            cout << endl;
            return 0;
        }
       
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i && j) || !pode(a + i, b + j) || p[a + i][b + j]) continue;
                char c;
                if (i == -1) last[a + i][b + j] = 'U';
                else if (i == 1) last[a + i][b + j] = 'D';
                else if (j == -1) last[a + i][b + j] = 'L';
                else last[a + i][b + j] = 'R';
                fila.push(par(a + i, b + j));
                p[a + i][b + j] = p[a][b] + 1;
            }
        }
    }

    cout << "NO" << endl;
}