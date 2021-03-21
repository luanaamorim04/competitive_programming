#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int lados[n], x = 0, soma = 0, maior;
    for (int i = 0; i < n; i++)
    {
        cin >> lados[i];
        soma += lados[i];
    }

    sort(lados, lados + n);
    for (int i = n - 1; i >= 2; i--)
    {
        maior = lados[i];
        soma -= maior;
        if (soma > maior)
        {
            cout << n - x << endl;
            return 0;
        }
        x++;
    }

    cout << 0 << '\n';
}