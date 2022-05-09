#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll x, q, b[60000], num, dig;

ll f(ll x)
{
    return (x*(x + 1))>>1;
}

int main()
{_  
    b[1] = 1;
    for (int i = 2; i <= 50000; i++)
    {
        b[i] = b[i - 1] + (int)log10(i) + 1;
        b[i] += b[i - 1] - b[i - 2];
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        num = 0;
        ll ini = 1, fim = 50000, meio;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (b[meio] >= x) fim = meio - 1;
            else ini = meio + 1;
        }

        x = b[fim + 1] - x;
        num = fim + 1;
        while (1)
        {
            if (x >= (int)log10(num) + 1)
            {
                x -= ((int)log10(num) + 1);
                num--;
            }
            else
            {
                while (x--) num /= 10;
                cout << num % 10 << endl;
                break;
            }
        }
    }
}