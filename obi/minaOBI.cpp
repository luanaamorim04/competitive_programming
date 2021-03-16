#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, pair<int, int> >
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, tab[101][101], soma[101][101];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tab[i][j];
            soma[i][j] = INF;
        }
    }

    fila.push(make_pair(0, make_pair(1, 1)));
    soma[1][1] = 0;

    while (!fila.empty())
    {
        int a = fila.top().second.first, b = fila.top().second.second,
        d = fila.top().first; fila.pop();

        if (a < 1 || b < 1 || a > n || b > n) continue;

        if (d > soma[a][b]) continue;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i && j) continue;
                if (soma[a + i][b + j] > soma[a][b] + tab[a + i][b + j])
                {
                    soma[a + i][b + j] = soma[a][b] + tab[a + i][b + j];
                    fila.push(make_pair(soma[a][b], make_pair(a + i, b + j)));
                }
            }
        }
    }

    cout << soma[n][n] << endl;
}