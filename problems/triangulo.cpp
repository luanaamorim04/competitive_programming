#include <iostream>
#define MOD 2147483647

using namespace std;

int main()
{
    long long n, a = 3, ans = 1;
    cin >> n;

    while (n > 0)
    {
        if (n%2) ans = ((ans % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        n /= 2;
    }

    cout << ans % MOD << endl;
}