#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll t, n, b, ini, meio, fim, num, sobra, resp;

ll bloco(int x)
{
    ll k = 1, tot = 0;
    for (int i = 0; i <= (int) log10(x); i++)
    {
        tot += (((x-k+1)*(x-k+2))>>1);
        k *= 10;
    }
    return tot;
}

ll dig(int x)
{
    ll k = 1, tot = 0;
    for (int i = 0; i <= (int) log10(x); i++)
    {
        tot += (x-k+1);
        k *= 10;
    }
    return tot;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        ini = 1, fim = 1e9;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (bloco(meio) >= n) fim = meio - 1;
            else ini = meio + 1;
        }

        //cout << "bloco: " << fim + 1 << endl;
        
        sobra = dig(++fim) - (bloco(fim) - n);
        //cout << "sobra1: " << sobra << endl; 
        ini = 1;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (dig(meio) >= sobra) fim = meio - 1;
            else ini = meio + 1;
        }

        //cout << "numero: " << fim + 1 << endl;

        num = fim + 1;
        sobra = dig(num) - sobra;

        //cout << "sobra2: " << sobra << endl; 
        
        while (sobra--) num /= 10;

        resp = num % 10;
        cout << resp << endl;
    }
}
