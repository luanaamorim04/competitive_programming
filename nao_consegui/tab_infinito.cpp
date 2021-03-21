#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long a, b, x, y, ansX, ansY, i;

int main()
{_
    cin >> a >> b;
    
    for (i = 1; i <= 1000000; i++)
    {
        if (ansX && ansY) break;

        x = ((a % b) * (i % b)) % b;
        y = ((b % a) * (i % a)) % a;

        if (x == 1 && ansX == 0)
            ansX = i + (a * i / b);

        if (y == 1 && ansY == 0)
            ansY = i + (b * i / a);
    }

    if (ansY && ansX > ansY) ansX = ansY;
    
    if (ansX)
        cout << ansX << endl;
    else 
        cout << "IMPOSSIVEL\n";
}