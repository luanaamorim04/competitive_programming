#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int m, n, pos[100001], mov[100001], ini = 1, fim, res[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);
    
    for (int i = 0; i < m; i++)
        scanf("%d", &mov[i]);

    fim = mov[1];

    for (int i = 0; i < m - 1; i++)
    {
        if (mov[i] < mov[i + 1] && i > 0)
        {
            ini = mov[i] + 1;
            fim = mov[i + 1];
        }
        else if (mov[i] > mov[i + 1] && i > 0)
        {
            ini = mov[i + 1];
            fim = mov[i] - 1;
        }

        for (int j = ini; j <= fim; j++)
            res[pos[j - 1]]++;
        
    }

    for (int i = 0; i < 10; i++)
        printf("%i ", res[i]);

    cout << '\n';
}