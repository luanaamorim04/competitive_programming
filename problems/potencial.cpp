#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{_
    long long n, mod, ans, a, b;
    while (cin >> n)
    {
        mod = 1;
        a = n;
        while (a > 0)
        {
            a /= 10;
            mod *= 10;
        }

        ans = 1;
        a = n;
        b = n;
        while (b > 0)
        {
            if (b % 2) ans = ((ans % mod) * (a % mod)) % mod;
            a = ((a % mod) * (a % mod)) % mod;
            b /= 2;
        }

        if (ans == n) cout << "SIM\n";
        else cout << "NAO\n";
    }
}