#include <iostream>
#define ll long long

using namespace std;

ll x, y, n, c;

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
    cin >> c;
    while (c--)
    {
        cin >> x >> y >> n;
        cout << fexpo(x, y, n) << endl;
    }

    cin >> c;
}