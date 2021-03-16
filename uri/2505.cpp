#include <iostream>
#define ll long long

using namespace std;

ll x, y, n, c, dig;

ll fexpo(ll x, ll y, ll n)
{
    ll resp = 1;
    ll mod = 1;
    while (n--) mod *= 10;
    while (y > 0)
    {
        if (y & 1) resp = (resp * x) % mod;
        x = (x * x) % mod;
        y>>=1;
    }
    return resp;
}
                                              
int main()
{
    while (cin >> n)
    {
        int k = n;
        dig = 0;
        while (k)
        {
            dig++;
            k/=10;
        }
        cout << (fexpo(n, n, dig) == n ? "SIM" : "NAO") << endl;
    }
}