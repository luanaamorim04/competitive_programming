#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= abs(b - c)) cout << "EH SUFICIENTE\n";
    else cout << "NAO EH SUFICIENTE\n";
}