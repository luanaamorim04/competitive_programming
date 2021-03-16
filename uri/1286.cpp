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

int n, m, dp[33], v[22], p[22];

int main()
{_  
    while (cin >> n && n)
    {
        cin >> m;
        for (int i = 0; i <= m; i++)
            dp[i] = 0;

        for (int i = 0; i < n; i++)
            cin >> v[i] >> p[i];

        for (int i = 0; i < n; i++)
            for (int j = m; j >= p[i]; j--)
                dp[j] = max(dp[j], dp[j - p[i]] + v[i]);

        cout << dp[m] << " min." << endl;
    }
}   