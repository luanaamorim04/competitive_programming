#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// busca binaria!!!

int n, m, faixas[100000], p[100000], f[100000];

int busca(int x)
{
    int ini = 0, fim = n - 1, meio, count = 0, res;

    while (ini <= fim && count < 35)
    {
        meio = (ini + fim) / 2;
        if (x < faixas[meio])
        {
            res = p[meio];
            fim = meio - 1;
        }

        if (x >= faixas[meio])
            ini = meio + 1;
        
        if (x >= faixas[n - 2])
            res = p[n - 1];

        count++;
    }
    return res;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
        cin >> faixas[i];
    
    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < m; i++)
    {
        cin >> f[i];
        cout << busca(f[i]) << ' ';
    }

    cout << '\n';
}