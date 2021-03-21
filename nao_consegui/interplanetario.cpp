#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define INF (int) (1e9 + 9)
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 100009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, temp[402], a, b, c, k, t, q, ver[402], ans[2][402][402][402], idx;

int cmp(int a, int b)
{
    return temp[a] < temp[b];
}

int main()
{_  
    cin >> n >> m;
    temp[0] = INF;
    temp[n + 1] = INF;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= 401; j++)
            for (int k = 0; k <= 401; k++)
                for (int l = 0; l <= 401; l++)
                {
                    ans[i][j][k][l] = INF;
                    ans[i][j][k][l] = INF;
                }

    for (int i = 1; i <= n; i++)
    {
        ver[i] = i;
        cin >> temp[i];
    }

    sort(ver+1, ver+n+1, cmp);

    while (m--)
    {
        cin >> a >> b >> c;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j <= 401; j++)
            {
                ans[i][j][a][b] = c;
                ans[i][j][b][a] = c;
            }
    }

    // para t == 0
    idx = 0;
    for (int x = 1; x <= n; x++)
    {
        if (temp[ver[x]] != temp[ver[x - 1]]) idx++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                ans[0][idx][i][j] = min(ans[0][idx][i][j], ans[0][idx - 1][i][j]);
                ans[0][idx][i][j] = min(ans[0][idx][i][j], ans[0][idx][ver[x]][j] + ans[0][idx][i][ver[x]]);
            }
    }

    // para t == 1
    idx = 0;
    for (int x = n; x >= 1; x--)
    {
        if (temp[ver[x]] != temp[ver[x + 1]]) idx++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                ans[1][idx][i][j] = min(ans[1][idx][i][j], ans[1][idx - 1][i][j]);
                ans[1][idx][i][j] = min(ans[1][idx][i][j], ans[1][idx][ver[x]][j] + ans[1][idx][i][ver[x]]);
            }
    }

    cin >> q;
    while (q--)
    {
        cin >> a >> b >> k >> t;
        if (k > idx) k = idx;
        cout << (ans[t][k][a][b] == INF ? -1 : ans[t][k][a][b]) << endl;
    }
}