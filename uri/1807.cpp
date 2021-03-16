#include <iostream>
#define ll long long
#define MOD (ll) ((1LL<<31) - 1)

using namespace std;

ll x, y, n, c, dig;

ll fexpo(ll x, ll y, ll n)
{
    ll resp = 1;
    while (y > 0)
    {
        if (y & 1) resp = (resp * x) % n;
        x = (x * x) % n;
        y>>=1;
    }
    return resp;
}
                                              
int main()
{
    cin >> n;
    cout << fexpo(3, n, MOD) << endl;
}