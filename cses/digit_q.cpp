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

ll num, n, k, sobra, ini, meio, fim;

int LOG(ll x)
{
    int resp = 0;
    while (x) x/=10 ,++resp;
    return resp;
}

ll dig(ll x)
{
    ll tot = 0LL, y = 1LL, l = LOG(x);
    for (int i = 1; i <= l; i++)
    {
        tot += (x-y+1LL);
        y *= 10LL;
    }
    return tot;
}

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> k;
        ini = 1, fim = k;
        while (ini <= fim)
        {
            meio = ini + ((fim-ini)/2LL);
            if (dig(meio) >= k) fim = meio - 1LL;
            else ini = meio + 1LL;
        }

        num = fim + 1;
        sobra = dig(num) - k;
        while (sobra--) num /= 10;
        cout << (num % 10) << '\n';
    }
}
