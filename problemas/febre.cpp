#include <iostream>
#include <string>

using namespace std;

long long n, k, m, dp[1003], a[1002], passou[1003];

long long f(long long x)
{
    if (passou[x]) return dp[x];
    passou[x] = 1;

    for (int i = 1; i <= n; i++)
        dp[x] = (dp[x] + ((a[i] * f(x - i)) % m) + m) % m;

    return dp[x];
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i];
        dp[i] %= m;
        passou[i] = 1;
    }

    cout << f(k) << endl;
}