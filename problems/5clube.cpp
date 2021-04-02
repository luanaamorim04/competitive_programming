#include <iostream>
#include <vector>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, numeros[1003], idx, troca, ok, k, last ;

int main()
{_
    cin >> n;
    troca = 10;
    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i];
        if (numeros[i] == 5 || numeros[i] == 0)
        {
            if (troca >= numeros[i]) 
            {
                troca = numeros[i];
                idx = i;
            }
        }
    }

    if (troca == 10)
    {
        cout << -1;
        return 0;
    }

    last = numeros[n - 1];

    if (last > troca) ok = 1;

    for (int i = 0; i < n; i++)
    {
        if ((numeros[i] == 5 || numeros[i] == 0) && ok)
        {
            if (ok && last > numeros[i])
            {
                numeros[n - 1] = numeros[i];
                cout << last << ' ';
                last = -1;
                continue;
            }
        }
        else if (!ok && i == idx)
        {
            numeros[n - 1] = numeros[i];
            cout << last << ' ';
            continue;
        }
        cout << numeros[i] << ' ';
    }
}