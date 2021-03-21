#include <iostream>
#define MOD (int) (1e9 + 7)

using namespace std;

int n;

int f(int n)
{
    if (!n) return 1;
    return (2*f(n - 1)) % MOD;
}

int main()
{
    cin >> n;
    cout << f(n) << endl;
}