#include <iostream>

using namespace std;

int res = 0;

int f(int n)
{
    cout << n << ' ';
    if (n == 1) return 0;
    return (n % 2 ? f((3 * n) + 1) : f(n / 2));
}

int main()
{
    for (int i = 1; i < 11; i++)
    {
        cout << i << " -> ";
        f(i);
        cout << endl;
    }
}