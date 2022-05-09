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

ll t, n, arr[1<<20], resp, memo[1<<20];

ll f(int idx)
{
    if (idx >= n) return 0;
    if (~memo[idx]) return memo[idx];
    return memo[idx] = f(idx + arr[idx]) + arr[idx];
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        resp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            memo[i] = -1;
        }
        for (int i = 0; i < n; i++)
            resp = max(resp, f(i));
        cout << resp << endl;
    }
}
