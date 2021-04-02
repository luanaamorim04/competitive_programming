#include <iostream>
#define ll long long

using namespace std;

ll n, m;

int main()
{
    cin >> n >> m;
    if (n > 26) cout << m;
    else cout << (m % (1<<n)) << endl;
}