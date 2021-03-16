#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[101][101], A, B, dias, t, passou[101][101];

int main()
{_
    cin >> t;
    
    while (cin >> n >> m)
    {    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j ++)
            {
                cin >> tab[i][j];
                passou[i][j] = 0;
            }
        }

        cin >> A >> B;
        dias = 0;

        queue<pair<int, int> > fila;
        fila.push(make_pair(A, B));
        passou[A][B] = 1;
        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop();
            dias = max(dias, passou[a][b]);

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (passou[a + i][b + j] || !tab[a + i][b + j]) continue;
                    fila.push(make_pair(a + i, b + j));
                    passou[a + i][b + j] = passou[a][b] + 1;
                }
            }
        }

        std::cout << dias - 1 << endl;
    }
}
