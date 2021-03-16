#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, v, k, a1, a2;
char fazenda[251][251], lobo, ovelha;

void dfs(int a, int b)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (fazenda[a][b] == '#') return;

    v += (fazenda[a][b] == lobo);
    k += (fazenda[a][b] == ovelha);

    fazenda[a][b] = '#';
    
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
}

int main()
{_
    cin >> n >> m;
    lobo = 'v';
    ovelha = 'k';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> fazenda[i][j];
            a1 += (fazenda[i][j] == 'k');
            a2 += (fazenda[i][j] == 'v');
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fazenda[i][j] != '#')
            {
                v = 0, k = 0;
                dfs(i, j);
                if (k > v) a2 -= v;
                else a1 -= k;
            }
        }
    }


    cout << a1 << ' ' << a2 << endl;
}