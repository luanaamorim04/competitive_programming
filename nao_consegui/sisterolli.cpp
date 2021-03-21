#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long dp[100000], ans, n, i;

int f(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 5;
    if (x == 3) return 50;
    if (dp[x] != -1) return dp[x];
    dp[x] = f(x - 1) + f(x - 2) - f(x - 3) < n;
}
int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (i = 1; i <= n; i++)
    {
        f(i);
        if (dp[i] <= n) ans++;
        else break;
    }
    cout << ans << endl;

}