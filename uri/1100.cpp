#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

char c, d;
int n, m, nivel[10][10], ans;
queue<par> fila;

int main()
{_
    while (cin >> c >> n >> d >> m)
    {
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++)
                nivel[i][j] = -1;

        fila.push(make_pair(9 - n, c - 'a' + 1));
        nivel[9 - n][c - 'a' + 1] = 1;
        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop();
            if (a == 9 - m && b == d - 'a' + 1) ans = nivel[a][b] - 1;

            for (int i = -2; i <= 2; i++)
            {
                for (int j = -2; j <= 2; j++)
                {
                    int x = abs(i), y = abs(j);
                    if (min(x, y) != 1 || max(x, y) != 2) continue;
                    if (nivel[a + i][b + j] != -1) continue;
                    fila.push(make_pair(a + i, b + j));
                    nivel[a + i][b + j] = nivel[a][b] + 1;
                }
            }
        }

        cout << "To get from " << c << n << " to " << d << m << " takes " << ans << " knight moves.\n";
    }
}