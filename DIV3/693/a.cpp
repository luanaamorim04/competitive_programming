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

ll t, x, y, n, resp;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> n;
        resp = 1;
        while ((x & 1) == 0)
        {
            resp*=2;
            x>>=1;
        }
        while ((y & 1) == 0)
        {
            resp*=2;
            y>>=1;
        }
        cout << (resp >= n ? "YES" : "NO") << endl;
    }
}
