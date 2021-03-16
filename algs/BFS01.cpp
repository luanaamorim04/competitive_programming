#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <deque>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

deque<par> fila;
int t, n, m, resp, vis[1001][1001];
char tab[1001][1001];

int pos(int a, int b)
{
    return (a >= 0 && a <= n - 1 && b >= 0 && b <= m - 1);
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> tab[i][j];
                vis[i][j] = INF;
            }

        fila.push_front(par(0, 0));
        vis[0][0] = 0;
        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop_front();

            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                    if ((i && j) || (!i && !j)) continue;
                    if (!pos(a + i, b + j)) continue;
                    if (tab[a][b] == tab[a + i][b + j] && vis[a + i][b + j] > vis[a][b]) 
                    {
                        fila.push_front(par(a + i, b + j));
                        vis[a + i][b + j] = vis[a][b];
                    }
                    if (tab[a][b] != tab[a + i][b + j] && vis[a + i][b + j] > vis[a][b] + 1)
                    {
                        fila.push_back(par(a + i, b + j));
                        vis[a + i][b + j] = vis[a][b] + 1;
                    }
                }
        }

        cout << vis[n - 1][m - 1] << endl;
    }
}