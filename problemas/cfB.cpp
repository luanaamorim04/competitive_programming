#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, a, ans, pause;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0, pause = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a)
            {
                if (pause) ans += i - pause;
                pause = i + 1;
            }
        }
        cout << ans << endl;
    }
}