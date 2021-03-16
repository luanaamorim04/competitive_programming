#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[505][505], ans, passou[1505][1505], x, y;
char c;
pair<int, int> k, l, tmp;
queue<pair<int, int> > fila;

pair<int, int> mais_longe(pair<int, int> k)
{
    fila.push(k);
    passou[k.first + x][k.second + y] = 1;

    while (!fila.empty())
    {
        int a = fila.front().first, b = fila.front().second; fila.pop();
        if (ans < passou[a + x][b + y])
        {
            tmp = make_pair(a, b);
            ans = passou[a + x][b + y];
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (j && i) continue;
                if (!tab[a + i][b + j] || passou[a + i + x][b + j + y]) continue;
                fila.push(make_pair(a + i, b + j));
                passou[a + i + x][b + j + y] = passou[a + x][b + y] + 1;
            }
        }
    }

    return tmp;
}

int main()
{_
    while (cin >> n >> m && n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> c;
                passou[i][j] = 0;
                passou[i + n][j + m] = 0;
                c == '.' ? tab[i][j] = 1 : tab[i][j] = 0;
                if (tab[i][j]) 
                {
                    k.first = i, k.second = j;
                }
            }

        ans = 0, x = 0, y = 0;
        l = mais_longe(k);
        ans = 0, x = n, y = m;
        mais_longe(l);
        cout << ans - 1 << endl;
    }
}