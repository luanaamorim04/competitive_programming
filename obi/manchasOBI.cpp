#include <iostream>

int pele[1005][1005], n, m;

void check(int x, int y)
{
    if (x < 0 || y < 0 || x > n - 1 || y > m - 1) return;
    if (pele[x][y] == 0) return;
    
    pele[x][y] = 0;
    check(x + 1, y);
    check(x - 1, y);
    check(x, y - 1);
    check(x, y + 1);
    return;
}

int main()
{
    std::cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> pele[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (pele[i][j] == 1)
            {
                check(i, j);
                res++;
            }
        }

    std::cout << res << std::endl;

}