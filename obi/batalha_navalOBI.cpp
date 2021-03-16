#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, ans, k, a, b, tmp, barcos[100010], mar[101][101], x;
char c;

void dfs(int a, int b, int c)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (mar[a][b] != -2) return;
    tmp++;

    mar[a][b] = c;
     
    dfs(a + 1, b, c);
    dfs(a - 1, b, c);
    dfs(a, b + 1, c);
    dfs(a, b - 1, c);
}

int main()
{_
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            c == '.' ? mar[i][j] = -1 : mar[i][j] = -2;
        }
    }

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mar[i][j] == -2)
            {
                dfs(i, j, ++x);
                barcos[x] = tmp;
                tmp = 0;
            }
        }
    }

    while (k--)
    {
        cin >> a >> b;
        if (mar[a-1][b-1] != -1)
        {
            barcos[mar[a-1][b-1]]--;
            ans += (!barcos[mar[a-1][b-1]]);
        }
    }

    cout << ans << endl;
}