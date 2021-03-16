#include <iostream>

using namespace std;

int t, n, fib[41], calls[41];

int main()
{
    cin >> t;
    fib[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        calls[i] = calls[i - 1] + calls[i - 2] + 2;
    }

    while (t--)
    {
        cin >> n;
        cout << "fib(" << n << ") = " << calls[n] << " calls = " << fib[n] << endl;
    }
}