#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int t, n, x, nums[9], memo[19684][10];

int f(int sum, int idx)
{
    if (sum <= 0) return sum;
    if (memo[sum][idx] != -1) return memo[sum][idx];
    int ans = -1000009;
    for (int i = idx; i <= 9; i++)
        ans = max(ans, f(sum - nums[i], i + 1));

    return memo[sum][idx] = ans;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i <= 9; i++)
        nums[i] = pow(3, i);

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << n - f(n, 0) << endl;
    }
}