#include <iostream>
#include <vector>

using namespace std;

int n, arr[109], soma, dp[100009], sz;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        soma += arr[i];
    }

    dp[0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = soma; i >= arr[j]; i--)
        {
            sz -= dp[i];
            if (i >= arr[j]) dp[i] |= dp[i - arr[j]];
            sz += dp[i];
        }
    }

    cout << sz << endl;
    for (int i = 1; i <= soma; i++)
        if (dp[i]) cout << i << ' ';

    cout << endl;
}