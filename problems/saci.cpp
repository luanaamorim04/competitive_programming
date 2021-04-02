#include <iostream>

using namespace std;
int toca[1010][1010], n, m;
long long soma = 0;

void caminho(int a, int b)
{
    soma++;
    if (toca[a][b] == 2 || a < 0 || a > n - 1 || b < 0 || b > n - 1) return;
    toca[a][b] = 0;
    if (toca[a + 1][b] != 0 && a < n - 1)
        caminho(a + 1, b);

    else if (toca[a - 1][b] != 0 && a > 0)
        caminho(a - 1, b);

    else if (toca[a][b + 1] != 0 && b < m - 1)
        caminho(a, b + 1);

    else if (toca[a][b - 1] != 0 && b > 0)
        caminho(a, b - 1);

    return;
}

int main()
{
    int r, s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> toca[i][j];
            if (toca[i][j] == 3)
            {
                r = i;
                s = j;
            }
        } 

    caminho(r, s);
    cout << soma << '\n';
}