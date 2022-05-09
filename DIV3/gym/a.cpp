#include <iostream>

using namespace std;

int n, a, b, c, menor, maior;

int main()
{
    cin >> n >> a >> b;
    while (n--)
    {
        cin >> c;
        maior += (c + a > b || abs(c - a) > b);
        menor += (abs(c - a) > b && c + a > b);
    }

    cout << menor << ' ' << maior << endl;
}