#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, b, t, memo[10009];

int f(int n)
{
    if (n == 0) return 0;
    if (n < 0) return -INF;
    if (memo[n] != -1) return memo[n];
    return memo[n] = 1 + max(f(n - a), f(n - b));
}

int main()
{_
    while (cin >> a >> b >> t)
    {
        for (int i = 0; i <= t; i++)
            memo[i] = -1;

        for (int i = 0; i <= t; i++)
        {
            int x = f(t - i);
            if (x >= 0)
            {
                cout << x;
                if (i) cout << ' ' << i;
                cout << endl;
                break;
            }
        }
    }
}