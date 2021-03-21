#include <iostream>

using namespace std;

int k;

int main()
{
    while (cin >> k)
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = i + 1; j <= k; j++)
            {
                if (k*(i + j) == i*j) cout << 1 << " / " << k << " = " << 1 << " / " << i << " + " << 1 << " / " << j << endl;
            }
        }
    }
}