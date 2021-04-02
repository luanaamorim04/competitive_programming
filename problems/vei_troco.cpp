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

int dp[1009], n, m, a[1009];

int f(int soma)
{
    if (!soma) return 1;
    if (soma < 0) return 0;
    if (dp[soma] != -1) return dp[soma];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans |= f(soma-a[i]);

    return dp[soma] = ans;
}

int main()
{_
    cin >> n >> m;
    // for (int i = 0; i <= m; i++)
    //     dp[i] = -1;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] |= dp[i - a[j]];
        }
    }

    cout << (dp[m] ? 'S' : 'N') << endl;
}