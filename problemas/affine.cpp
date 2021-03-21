#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <map>
#define ll long long

using namespace std;

ll n, t, a, b, cifra[100005], i, msg;

map<ll, ll> mapa;

ll inv(ll a, ll b)
{   
    return a > 1 ? b-inv(b%a,a)*b/a: 1;
}

int main()
{_
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> cifra[i];

    cin >> t >> a >> b;

    for (i = 0; i < n; i++)
    {
        msg = (cifra[i] - (b%t) + t) % t;
        msg = (msg * inv(a, t)) % t;

        if (!cifra[i]) cifra[i] = -1;

        if (!mapa[msg])
        {
            mapa[msg] = cifra[i];
        }
        else if (mapa[msg] != cifra[i])
        {
            cout << "DECIFRAGEM AMBIGUA\n";
            return 0;
        }
        cifra[i] = msg;
    }

    for (int i = 0; i < n; i++)
        cout << cifra[i] << (i < n - 1 ? ' ' : '\n');
}

