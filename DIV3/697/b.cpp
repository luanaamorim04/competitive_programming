#include <iostream>
#include <cstring>

using namespace std;

int n, t, memo[1000001];

int f(int k)
{
    if (k <= 0) return !k;
    if (memo[k] != -1) return memo[k];
    return memo[k] = f(k - 2020) | f(k - 2021);
}

int main()
{
    cin >> t;
    memset(memo, -1, sizeof(memo));
    while (t--)
    {
        cin >> n;
        cout << (f(n) ? "YES" : "NO") << endl;
    }
}