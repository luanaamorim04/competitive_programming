#include <iostream>

using namespace std;

int main()
{
    int m, n, costa = 0;
    cin >> m >> n;
    char c[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] == '#')
            {
                if (i == 0 || c[i - 1][j] == '.')
                    costa++;
                else if (i == m - 1 || c[i + 1][j] == '.')
                    costa++;
                else if (j == 0 || c[i][j - 1] == '.')
                    costa++;
                else if (j == n - 1 || c[i][j + 1] == '.')
                    costa++;
            }
        }

    cout << costa << endl;
}