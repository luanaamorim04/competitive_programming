#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, arr[200001], x, y;

ll mdc(ll a, ll b)
{
    if (!b) return a;
    return mdc(b, a%b);
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    x = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++)
    {   
        x = mdc(x, arr[i + 1]-arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        y += (arr[n - 1] - arr[i]) / x;
    }

    cout << y << ' ' << x << endl;
}