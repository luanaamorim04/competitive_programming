#include <iostream>

using namespace std;
long long n, a, b;

int main()
{
    cin >> n;
    while (n % 5 == 0)
    {
        n /= 5;
        a++;
    }

    while (n % 2 == 0)
    {
        n /= 2;
        b++;
    }

    a = a*(a + 1) / 2;
    b = b*(b + 1) / 2;
    cout << min(a, b) << endl;
}