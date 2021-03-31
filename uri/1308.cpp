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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, x;

int f(ll y)
{
    return (((y*(y+1))>>1LL) <= x);
}

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> x;
        ll ini = 0, meio, fim = 1e9;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (f(meio)) ini = meio + 1; 
            else fim = meio - 1;
        }
        cout << ini - 1 << endl;
    }
}   
