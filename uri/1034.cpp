#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, m, a[30], dp[1000090];

int main()
{_  
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i <= m; i++)
            dp[i] = INF;

        dp[0] = 0;
        for (int peso = 1; peso <= m; peso++)
        {   
            for (int val = 0; val < n; val++)
            {
                if (peso >= a[val])
                    dp[peso] = min(dp[peso - a[val]] + 1, dp[peso]);
            }
        }

        cout << dp[m] << endl;
    }
}