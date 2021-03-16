#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[505][505], passou[505][505];
queue<pair<int, int> > fila;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];

    fila.push(make_pair(0, 0));
    passou[0][0] = 1;

    while (!fila.empty())
    {
        int a = fila.front().first, b = fila.front().second; fila.pop();

        if (a == n - 1 && b == m - 1)
        {
            cout << passou[a][b] - 1 << endl;
            return 0;
        }

        for (int i = -2; i <= 2; i++)
        {
            for (int j = -2; j <= 2; j++)
            {
                if (a + i < 0 || a + i > n - 1 || b + j < 0 || b + j > m - 1) continue;
                if (passou[a + i][b + j] || !tab[a + i][b + j]) continue;
                passou[a + i][b + j] = passou[a][b] + 1;
                fila.push(make_pair(a + i, b + j));
            }
        }
    }

    cout << -1 << endl;
}