#include <iostream>

using namespace std;

long long t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ok = 0;
        for (int i = 0; i < 50; i++)
        {
            if (n == (1LL << i))
            {
                cout << "NO" << endl;
                ok = 1;
                break;
            }
        }

        if (!ok) cout << "YES" << endl;
    }
}