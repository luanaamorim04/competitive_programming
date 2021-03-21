#include <iostream>

using namespace std;

int n, x, a[109], dp[1000009];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <= x; i++)
        dp[i] = 99999999;

    dp[0] = 0;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j]) dp[i] += dp[i - a[j]];
        }
    }

    cout << (dp[x] != 99999999 ? dp[x] : -1) << endl;
}