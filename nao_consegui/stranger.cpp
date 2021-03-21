#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int n, m, x, y, buracos, tamanho = 1, ok, grande;
char dutos[105][105];

void check(int a, int b)
{
    if (a < 0 || b < 0 || a > n - 1 || b > m - 1) return;
    if (dutos[a][b] == 'X')
    {
        ok = 1;
        return;
    }
    if (dutos[a][b] == 'O')
    {
        buracos++;
        if (grande == 1) return;
        grande = 1;
    }
    else
    {
        grande = 0;
    }

    tamanho++;
    

    if (a < n - 1 && (dutos[a + 1][b] == 'V' || dutos[a + 1][b] == 'O')) check(a + 1, b);
    else if (a > 0 && (dutos[a - 1][b] == 'A' || dutos[a - 1][b] == 'O')) check(a - 1, b);
    else if (b < m - 1 && (dutos[a][b + 1] == '>' || dutos[a][b + 1] == 'O')) check(a, b + 1);
    else if (b > 0 && (dutos[a][b - 1] == '<' || dutos[a][b - 1] == 'O')) check(a, b - 1);

    return;
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> dutos[i][j];
            if (dutos[i][j] == 'E')
            {
                x = i;
                y = j;
            }
        }

    check(x + 1, y);
    if (ok)
    {
        cout << tamanho << ' ' << buracos;
        return 0;
    }
    else
    {
        tamanho = 1;
        buracos = 0;
        grande = 0;
    }
    
    check(x - 1, y);
    if (ok)
    {
        cout << tamanho << ' ' << buracos;
        return 0;
    }
    else
    {
        tamanho = 1;
        buracos = 0;
        grande = 0;
    }
    check(x, y + 1);
    if (ok)
    {
        cout << tamanho << ' ' << buracos;
        return 0;
    }
    else
    {
        tamanho = 1;
        buracos = 0;
        grande = 0;
    }
    check(x, y - 1);
    if (ok)
    {
        cout << tamanho << ' ' << buracos;
        return 0;
    }

    cout << "No meio do caminho tinha um buraco\n";
}