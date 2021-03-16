#include <iostream>
#include <map>
#define MAXN 1<<20

using namespace std;

long long n, m, arr[41], somas[MAXN], soma, k;
map<long long, int> mapa;

int main()
{
    cin >> n >> m;
    k = n/2;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < (1LL<<k); i++)
    {  
        soma = 0;
        for (int j = 0; j < k; j++)
            if((1LL<<j) & i) soma += arr[j];

        mapa[soma] = 1;
    }

    for (int i = 0; i < (1LL<<(n-k)); i++)
    {
        soma = 0;
        for (int j = 0; j < (n - k); j++)
            if ((1LL<<j) & i) soma += arr[k + j];

        if (mapa.count(m - soma)) 
        {
            cout << "sim\n";
            return 0;
        }
    }

    cout << "nao\n";
}