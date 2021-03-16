#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, ans, tab[2025][2025];
char c;
queue<pair<int, int> > fila;

int main()
{_
    cin >> n >> m;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == 'o') tab[i][j] = 0;
            else tab[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (tab[i][j])
            {
                fila.push(make_pair(i, j));
                while (!fila.empty())
                {
                    int a = fila.front().first, b = fila.front().second; fila.pop();
                    if (!tab[a][b]) continue;
                    tab[a][b] = 0;
                    if (tab[a + 1][b]) fila.push(make_pair(a + 1, b));
                    if (tab[a - 1][b]) fila.push(make_pair(a - 1, b));
                    if (tab[a][b + 1]) fila.push(make_pair(a, b + 1));
                    if (tab[a][b - 1]) fila.push(make_pair(a, b - 1));
                }
                ans++;
            }
        }
    }

    cout << ans << endl;
}