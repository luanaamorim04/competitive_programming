#include <iostream>

int mdc(int a, int b)
{
    return (b == 0 ? a : mdc(b, a%b));
}

int main()
{
    int n, num[100001], dp[100000];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> num[i];

    dp[0] = mdc(num[0], num[1]);

    for (int i = 1; i < n - 1; i++)
        dp[i] = mdc(dp[i - 1], num[i + 1]);

    std::cout << dp[n - 2];
}