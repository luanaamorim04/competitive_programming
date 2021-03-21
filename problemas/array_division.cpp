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

ll n, k, arr[200001];

int f(ll x)
{
    ll d = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x) return 0;
        if (sum + arr[i] > x) sum = arr[i], ++d;
        else sum += arr[i];
    }
    
    return d <= k;
}

int main()
{_
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll ini = 1, meio, fim = (1e15);
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (f(meio)) fim = meio - 1;
        else ini = meio + 1;
    }
    cout << fim + 1 << endl;
}