#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = (n % 2 ? n - 1 : n); i >= 6; i-= 2)
        cout << i << ' ';

    cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << ' ';

    for (int i = 5; i <= (n % 2 ? n : n - 1); i += 2)
        cout << i << ' ';

    cout << endl;
}