#include <iostream>

using namespace std;

long long n, m, x, y, z, k, ans;

int main()
{
    cin >> n >> m >> x >> y >> z >> k;
    if (z < x && z < y)
    {
        ans += z*min(k, n + m);
        if (x > y)
        {
            if (k > n) m = max(0LL, m - (k - n));
            n = max(0LL, n - k);
        }
        else
        {
            if (k > m) n = max(0LL, n - (k - m));
            m = max(0LL, m - k);
        }   
    }
    else if (z < x)
    {
        ans += z*min(n, k);
        n = max(0LL, n - k);
    }
    else if (z < y)
    {
        ans += z*min(m, k);
        m = max(0LL, m - k);
    }

    cout << (ans) + (n*x) + (m*y) << endl;
}