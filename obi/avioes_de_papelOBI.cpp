#include <iostream>
#include <algorithm>
#define _ std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

int n, ans;

int main()
{_
    std::cin >> n;
    ans = 7;
    if (n > 10)
    {
        if (n > 30) ans += 20;
        else ans += (n - 10);
    }
    if (n > 30)
    {
        if (n > 100) ans += 140;
        else ans += 2*(n - 30);
    }
    if (n > 100)
    {
        ans += 5*(n - 100);
    }

    std::cout << ans << '\n';
}