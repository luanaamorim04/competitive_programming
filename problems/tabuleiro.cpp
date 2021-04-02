#include <iostream>

using namespace std;

int tab[150][150];

int main()
{
    int n, soma;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            soma = 0;
            cin >> tab[i][j];
            if (i > 0 && j > 0)
            {
                for (int k = -1; k <= 0; k++)
                    for (int l = -1; l <= 0; l++)
                        if (l != 0 || k != 0)
                            soma += tab[i + k][j + l];

                if (soma >= 2) tab[i][j] = 0;
                else tab[i][j] = 1;
            }
        }
    }

    cout << tab[n - 1][n - 1] << endl;
}