#include <iostream>

int n, m, x, y;
char mapa[150][150];

void find(int a, int b)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (mapa[a][b] == '.') return;
    mapa[a][b] = '.';
    x = a;
    y = b;
    find(a + 1, b);
    find(a - 1, b);
    find(a, b + 1);
    find(a, b - 1);
    return;
}

int main()
{
    std::cin >> n >> m;
    int k, l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            std::cin >> mapa[i][j];
            if (mapa[i][j] == 'o')
            {
                k = i;
                l = j;
            }
        }

    find(k, l);
    std::cout << x + 1 << ' ' << y + 1 << '\n';
}