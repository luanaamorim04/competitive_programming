#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num[100000];

int n, k;

int busca(int x)
{
    int ini = 1, fim = n, meio;
    long long res;

    while (ini <= fim)
    {
        meio = (ini + fim) / 2;

        if (x == num[meio])
        {
            res = num[meio];
            return res;
        }
        else if (x > num[meio])
            ini = meio + 1;
        else if (x < num[meio])
            fim = meio - 1;
    }
    return -12345678;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int a = busca(k - num[i]);
        if (a == -12345678)
            continue;

        cout << min(a, num[i]) << ' '<< max(a, num[i]) << '\n';
        return 0;
    }
}