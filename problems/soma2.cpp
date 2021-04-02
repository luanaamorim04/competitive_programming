#include <iostream>
#include <stdio.h>

using namespace std;

int n, k, numeros[100000], soma, i, j;
long long counter = 0;
int main()
{
    cin >> n >> k;

    for (i = 0; i < n; i++)
        scanf("%d", &numeros[i]);

    for (i = 0; i < n; i++)
    {
        if (numeros[i] > k)
            continue;
        soma = 0;
        for (j = 0; j < n - i; j++)
        {
            soma += numeros[i + j];
            if (soma == k)
                counter++;
            else if (soma > k)
                break;
        }
    }

    cout << counter << "\n";
    
}