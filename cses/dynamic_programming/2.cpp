#include <iostream> 

using namespace std;

int n, soma, dp[100009];

int main()
{
    cin >> n;
    soma = n * (n + 1) / 2;
    if (soma % 2) 
    {
        cout << 0 << endl;
        return 0;
    }

    soma /= 2;

    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = soma; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % 1000000007;
    }

    cout << dp[soma] << endl;
}