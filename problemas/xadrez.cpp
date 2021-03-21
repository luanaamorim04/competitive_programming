#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, t, ans;

int main()
{_
    cin >> n >> t;
    if (t == 1)
    {
        ans = (n)*(n - 1);
    }
    else if (t == 0)
    {
        ans = n;
    }
    else 
    {
        //ans = 1;
        for (int i = 1; i <= n - 2; i++)
        {
            ans += (n + 1 - i - 2) * i;
        }
    }

    cout << ans << endl;
}