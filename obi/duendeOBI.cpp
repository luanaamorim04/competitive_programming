#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[12][12], x, y, ans, nivel[13][13];
queue<pair<int, int> > fila;
pair<int, int> p;

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == 3)
            {
                x = i; y = j;
            }
        }
    }

    fila.push(make_pair(x, y));
    nivel[x][y] = 1;

    while (!fila.empty())
    {
        p = fila.front(); fila.pop();
        int a = p.first, b = p.second;
        
        if (a < 1 || b < 1 || a > n || b > m) continue;
        if (tab[a][b] == 2) 
        {
            nivel[a][b] = -1;
            continue;
        }
        if (!tab[a][b])
        {
            ans = nivel[a][b];
            break;
        }

        if (!nivel[a+1][b])
        {
            fila.push(make_pair(a+1, b)); 
            nivel[a+1][b] = nivel[a][b] + 1;
        }
        if (!nivel[a-1][b])
        {
            fila.push(make_pair(a-1, b)); 
            nivel[a-1][b] = nivel[a][b] + 1;
        }
        if (!nivel[a][b+1])
        {
            fila.push(make_pair(a, b+1)); 
            nivel[a][b+1] = nivel[a][b] + 1;
        }
        if (!nivel[a][b-1])
        {
            fila.push(make_pair(a, b-1)); 
            nivel[a][b-1] = nivel[a][b] + 1;
        }
    }

    cout << ans - 1 << endl;
}