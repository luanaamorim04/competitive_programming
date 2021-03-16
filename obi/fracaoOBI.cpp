#include <iostream>

using namespace std;

long long mdc(long long a, long long b)
{
    return (b == 0 ? a : mdc(b, a%b));
}

int main()
{
    long long n1, n2, d1, d2, nfinal, dfinal, x;
    cin >> n1 >> d1 >> n2 >> d2;

    dfinal = d1 * d2;
    nfinal = (n1 * d1) + (n2 * d2);

    x = mdc(dfinal, nfinal);
    dfinal /= x;
    nfinal /= x;
    
    cout << nfinal << ' ' << dfinal;
}