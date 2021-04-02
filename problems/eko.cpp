#include <iostream>
#include <algorithm>

using namespace std;

long long t, n, m, p[1000001], ini, meio, fim;

int f(int x)
{
    long long resp = 0;
    for (int i = 0; i < n; i++)
        resp += max(0LL, p[i] - x);

    return resp >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    ini = 1, fim = 1000000000LL, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (f(meio)) ini = meio + 1;
        else fim = meio - 1;
    }

    cout << (ini - 1LL) << endl;
}