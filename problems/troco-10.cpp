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

int n, m, a[1009], dp[1009];

int f(int soma)
{
    if (!soma) return 0;
    if (soma < 0) return INF;
    if (dp[soma] != INF) return dp[soma];
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, f(soma - a[i]) + 1);
    return dp[soma] = ans;
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= m; i++)
        dp[i] = INF;

    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
        }
    }

   cout << (dp[m] < 10 ? 'S' : 'N') << endl;
}