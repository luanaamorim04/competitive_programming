#include <iostream>

using namespace std;

int n, x, a[109], dp[1000009];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 1;
    for (int j = 0; j < n; j++)
        for (int i = a[j]; i <= x; i++)
            dp[i] = (dp[i] + dp[i - a[j]]) % 1000000007;

    cout << dp[x] << endl;
}