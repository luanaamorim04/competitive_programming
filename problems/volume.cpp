#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int V, T, x;

int main()
{_
    cin >> V >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x;
        V += x;
        if (V < 0) V = 0;
        if (V > 100) V = 100;
    }

    cout << V;
}