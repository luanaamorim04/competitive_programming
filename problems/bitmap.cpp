#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, m;
char tab[400][400];
int nivel[400][400];
queue<par> fila;

int pode(int a, int b)
{
    if (a < 0 || b < 0 || a == n || b == m) return 0;
    if (~nivel[a][b]) return 0;
    return 1;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                nivel[i][j] = -1;
                cin >> tab[i][j];
                if (tab[i][j] - '0') 
                {
                    fila.push(par(i, j)); 
                    nivel[i][j] = 0;
                }
            }
        }

        while (!fila.empty())
        {
            int a = fila.front().first, b = fila.front().second; fila.pop();
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (!pode(a + i, b + j) || (i && j)) continue;
                    nivel[a + i][b + j] = nivel[a][b] + 1;
                    fila.push(par(a + i, b + j));
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << nivel[i][j] << ' ';
            }
            cout << endl;
        }
    }
}