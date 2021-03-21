#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 9999999999
#define MOD 1000000007
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long a, b, c, d, n, ans, i;

int main()
{_  
    cin >> a >> b >> c >> d;
    ans = INF;
    for (i = 1; i*i <= c; i++)
    {
        if (c % i == 0)
        {
            if (!(i % a) && i % b && d % i)
                ans = min(ans, i);
            if (!((c/i) % a) && (c/i) % b && d % (c/i))
                ans = min(ans, c/i);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}