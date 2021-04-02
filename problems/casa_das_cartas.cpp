#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100009], m;

int cmp(int a, int b)
{
    if (a % m != b % m) return a % m > b % m;
    return a/m > b/m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    cout << endl;
}
