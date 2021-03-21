#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long

using namespace std;

map<ll, ll> mapa;
map<ll, ll> rep;

int main()
{
    ll n, m;
    cin >> m >> n;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        mapa[a] = b;
    }
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (rep[a] < b)
        rep[a] = b;
    }

    for (map<ll, ll>::iterator it = rep.begin(); it != rep.end(); it++)
    {
        if (mapa[it->first] < it ->second)
            cout << it->first << ' ' << it->second << endl;
    }

    

}