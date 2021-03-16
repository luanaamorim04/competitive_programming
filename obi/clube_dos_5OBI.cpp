#include <iostream>

using namespace std;

int main()
{
    int total;
    cin >> total;
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    if (total != (g + a + b + c - d - e - f))
        cout << 'S';
    else 
        cout << 'N';

}