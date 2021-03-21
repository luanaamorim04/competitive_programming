#include <iostream>
#include <string.h>

using namespace std;

long long arr[5001], memo[5001][5001], n;

long long f(int l, int r)
{
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    return memo[l][r] = max(arr[l] + min(f(l + 2, r), f(l + 1, r - 1)), arr[r] + min(f(l, r - 2), f(l + 1, r - 1)));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(memo, -1, sizeof(memo));

    cout << f(0, n - 1) << endl;
}