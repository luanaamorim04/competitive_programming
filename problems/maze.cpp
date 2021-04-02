#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, passou[1<<10][1<<10], ok, x, y;
char tab[1<<10][1<<10];

int pode(int a, int b)
{
    return (a >= 0 && b >= 0 && a < n && b < m && tab[a][b] != '#' && !passou[a][b]);
}

void dfs(int a, int b)
{
    ok = passou[a][b] = 1;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (!pode(a + i, b + j) || (i && j)) continue;
            ok = 0;
            dfs(a + i, b + j);
        }
    }

    if (ok && k) tab[a][b] = 'X', k--; 
}

int main()
{_
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == '.') x = i, y = j;
        }
    }

    dfs(x, y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << tab[i][j];
        }
        cout << endl;
    }
}
