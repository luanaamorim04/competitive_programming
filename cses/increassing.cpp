#include <iostream>
#include <cmath>

using namespace std;

long long  x, n, ans, maxn;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        maxn = max(maxn, x);
        ans += maxn - x;
    }

    cout << ans << endl;
}