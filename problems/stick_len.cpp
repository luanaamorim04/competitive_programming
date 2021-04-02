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

ll n, arr[1<<20], resp, resp1;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    if (n&1)
    {
        for (int i = 0; i < n; i++)
            resp += abs(arr[i] - arr[n/2]);
        cout << resp << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            resp += abs(arr[i] - arr[n/2]);
            resp1 += abs(arr[i] - arr[(n/2) - 1]);
        }
        cout << min(resp, resp1) << endl;
    }
}   
