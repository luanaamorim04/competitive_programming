#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, x, a = 0, b = 0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x < 50) a++;
        else if (x < 85) b++;

    }

    cout << a << ' ' << b;
}