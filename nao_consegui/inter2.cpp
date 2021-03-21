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

int n, m, temp[401], dist[2][401][401], q, ver[401], ans[2][401][401][401], idx, tot;

int cmp(int a, int b)
{
    return temp[a] < temp[b];
}

int main()
{_  
    cin >> n >> m;
    temp[0] = -INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dist[1][i][j] = INF;
            dist[0][i][j] = INF;
        }

    for (int i = 1; i <= n; i++)
    {
        ver[i] = i;
        cin >> temp[i];
    }

    sort(ver+1, ver+n+1, cmp);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[0][a][b] = c;
        dist[0][b][a] = c;
        dist[1][a][b] = c;
        dist[1][b][a] = c;
    }

    // para t == 0
    idx = 0;
    for (int x = 1; x <= n; x++)
    {
        if (temp[ver[x]] != temp[ver[x - 1]]) idx++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[0][i][j] = min(dist[0][i][j], dist[0][ver[x]][j] + dist[0][i][ver[x]]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans[0][idx][i][j] = dist[0][i][j];
    }

    // para t == 1
    tot = idx;
    idx = 0;
    for (int x = n; x >= 1; x--)
    {
        if (temp[ver[x]] != temp[ver[x - 1]]) idx++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[1][i][j] = min(dist[1][i][j], dist[1][ver[x]][j] + dist[1][i][ver[x]]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans[1][idx][i][j] = dist[1][i][j];
    }

    cin >> q;
    while (q--)
    {
        int t, a, b, k;
        cin >> a >> b >> k >> t;
        if (t == 0 && k > n) k = ;
        else if (t == 0 && k < n)
        cout << (ans[t][k][a][b] == INF ? -1 : ans[t][k][a][b]) << endl;
    }
}