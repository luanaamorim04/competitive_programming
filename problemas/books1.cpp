#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

long long t, n, m, p[50001], ini, meio, fim;
set<int> resp;

void last()
{
    long long soma_acumulada = p[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        soma_acumulada += p[i];
        if (soma_acumulada > fim + 1) soma_acumulada = p[i], resp.insert(i);
    }

    int i = 0;
    while (resp.size() < m - 1)
    {
        if (!resp.count(i)) resp.insert(i);
        i++;
    }
}

int f(long long x)
{
    long long pessoas = 1, soma_acumulada = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        soma_acumulada += p[i];
        if (soma_acumulada > x) soma_acumulada = p[i], pessoas++;
    }

    return pessoas;
}

int main()
{

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        ini = 1, fim = 5000000000LL;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (f(meio) <= m) fim = meio - 1;
            else ini = meio + 1;
        }

        last();

        for (int i = 0; i < n; i++) 
        {
            cout << p[i];
            if (resp.count(i)) cout << " / ";
            else cout << " ";
        }

        cout << endl;
        resp.clear();
    }
}