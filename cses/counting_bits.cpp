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

ll n, resp, tot, foi, k, logdois, r;
int LOG(ll n)
{
    while (n) tot += (n&1), n /= 2LL, r++;
    return r;
}

void f(ll n)
{
    resp += foi*(1LL<<n) + (n*(1LL<<(n-1)));
}

int main()
{_
    cin >> n;
    logdois = LOG(n);
    for (ll i = logdois - 1LL; i >= 0LL; i--)
    {
        if (n & (1LL<<i)) 
        {   
            if (tot == i + 1LL) 
            {
                f(i + 1);
                cout << resp << endl;
                return 0;
            }
            f(i);
            tot--, foi++;
        }
    }
    cout << resp + __builtin_popcountll(n) << endl;
}