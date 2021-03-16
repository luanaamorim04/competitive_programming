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

int n, t, dp[606], v[101], p[101], k;

int main()
{_  
    while (cin >> n >> t && n)
    {
        for (int i = 0; i <= t; i++)
            dp[i] = 0;

        for (int i = 0; i < n; i++)
            cin >> p[i] >> v[i];

        for (int i = 0; i <= t; i++)
            for (int j = 0; j < n; j++)
                if (i >= p[j]) dp[i] = max(dp[i], dp[i - p[j]] + v[j]);

        cout << "Instancia " << ++k << endl;
        cout << dp[t] << endl << endl;
    }
}