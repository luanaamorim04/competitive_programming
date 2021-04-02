#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[200][200], ans, tmp, cor;

void dfs(int a, int b)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (tab[a][b] != cor) return;
    tab[a][b] = -1;
    tmp++;
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
}

int main()
{_
    ans = 10000000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tab[i][j] != -1)
            {
                tmp = 0;
                cor = tab[i][j];
                dfs(i, j);
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;
}