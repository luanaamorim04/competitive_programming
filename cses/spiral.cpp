#include <iostream>

using namespace std;

int t, a, b;

int main()
{
    cin >> t;
    while (t--)
    {
        long long ans = 0;
        cin >> a >> b;
        long long k = max(a, b);
        ans = k * k;
        if (k % 2)
        {
            if (b == k)
            {
                ans -= (a - 1);
            }
            else if (a == k)
            {
                ans -= (a - 1);
                ans -= (k - b);
            }
        }
        else
        {
            if (a == k)
            {
                ans -= (b - 1);
            }
            else if (b == k)
            {
                ans -= (b - 1);
                ans -= (k - a);
            }
        }
        cout << ans << endl;
    }
}