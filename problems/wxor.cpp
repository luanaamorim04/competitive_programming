#include <iostream>

using namespace std;

int a[1005], n, m, k;

int main()
{
    while(cin >> n >> m >> k && n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        m %=n;

        cout << a[(k-m-1+n)%n] << endl;
    }
}