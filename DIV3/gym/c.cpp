#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    cin >> n >> a >> b;
    if (a + b == n + 2 || a + b == n + 4 || a + b == n + 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}