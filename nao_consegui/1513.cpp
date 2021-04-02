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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

queue<pair<par, int> > fila;
int n, m, k, passou[101][101], s1, s2, tot, resp, r1, r2;
char tab[101][101];

/*
    a, b
    a + 1, b + 2
    a + 2, b + 1


*/

int pode(int a, int b)
{
    return (a > 0 && b > 0 && a < n && b < m && !passou[a][b]);
}

void dfs(int a, int b, int k, int n)
{
    if (k == tot) resp = min(resp, n);
    if (!pode(a, b)) return;
    cout << a << ' ' << b << endl;
    k += (tab[a][b] == 'P');
    passou[a][b] = 1;
    dfs(a + 2, b + 1, k, n + 1);
    dfs(a + 2, b - 1, k, n + 1);
    dfs(a - 2, b + 1, k, n + 1);
    dfs(a - 2, b - 1, k, n + 1);
    dfs(a + 1, b - 2, k, n + 1);
    dfs(a - 1, b - 2, k, n + 1);
    dfs(a + 1, b + 2, k, n + 1);
    dfs(a - 1, b + 2, k, n + 1);
}

int main()
{_
    cin >> n >> m >> tot;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == 'C') s1 = i, s2 = j;
            else if (tab[i][j] == '#') passou[i][j] = -1;
        }

    resp = INF;
    while (!fila.empty())
    {
        int n = fila.front().second, a = fila.front().first.first, b = fila.front().first.second; fila.pop();
        for (int i = -2; i <= 2; i++)
        {
            for (int j = -2; j <= 2; j++)
            {
                
            }
        }
    }
    dfs(s1, s2, 0, 0);
    cout << resp << endl;
}
