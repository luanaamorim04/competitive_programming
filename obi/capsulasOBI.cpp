#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, ini, meio, fim, cap[100009], moedas;

int f(int dias)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k += (dias / cap[i]);
    }
    return k;
}

int main()
{_
    cin >> n >> moedas;
    for (int i = 0; i < n; i++)
    {
        cin >> cap[i];
    }

    ini = 0, fim = 100000009;
    while (ini <= fim)
    {
        meio = ini + ((fim - ini) / 2);

        if (f(meio) >= moedas) fim = meio - 1;
        else ini = meio + 1;
    }

    cout << fim + 1 << endl;
}