#include <iostream>

using namespace std;

int n, k, t;

int main()
{
    while (cin >> n)
    {
        k = n;
        cout << (n & -n) << endl;
        // for (int i = 31; i >= 0; i--)
        // {
        //     t = i;
        //     if (n & (1<<i)) break;
        // }
        // for (int i = 0; i < t/2; i++)
        // {
        //     if ((n & (1<<i)) != 0 && (n & (1<<(t-i))) != 0) continue;
        //     if (!(n & (1<<i)) && !(n & (1<<(t-i)))) continue;
        //     if (n & (1<<i))
        //     {
        //         n -= (1<<i);
        //         n |= (1<<(t-i));
        //     }
        //     else
        //     {
        //         n |= (1<<i);
        //         n -= (1<<(t-i));
        //     }

        //     //cout << ((n & (1<<i)) != 0);
        // }

        cout << n << endl;
    }
}