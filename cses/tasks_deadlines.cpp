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

ll resp, arr[1<<20], a, n;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] >> a;
        resp += a; 
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
        resp -= ((n-i)*arr[i]);
    
    cout << resp << endl;
}
