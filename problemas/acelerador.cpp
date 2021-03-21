#include <iostream>

using namespace std;

int main()
{
    int d, count = 1;
    cin >> d;

    while (true)
    {
        if ((d - 5) - (8 * count) == 1 || (d - 5) - (8 * count) == -7)
        {
            cout << 1 << endl;
            return 0;
        }
        else if ((d - 5) - (8 * count) == 2 || (d - 5) - (8 * count) == -6)
        {
            cout << 2 << endl;
            return 0;
        }
        else if ((d - 5) - (8 * count) == 3 || (d - 5) - (8 * count) == -5)
        {
            cout << 3 << endl;
            return 0;
        }

        count++;
    }
}