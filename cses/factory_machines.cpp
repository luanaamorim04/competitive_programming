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
#define INF 1e18
#define MAX 300000
#define MOD 1000000007
#define par pair<ll, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, m, x, resp, arr[1<<20];

ll f(ll x)
{
    ll resp = 0;
    for (int i = 0; i < n; i++)
    {
        resp += (x/arr[i]);
        if (resp >= m) return 1;
    }
    return resp >= m;
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll ini = 1, fim = INF, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2LL;
        if (f(meio)) fim = meio - 1LL;
        else ini = meio + 1LL;
    }
    cout << fim + 1LL << endl;
}
