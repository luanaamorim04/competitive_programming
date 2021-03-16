#include <iostream>
#include <set>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> numeros;

int main()
{_
    int n, x, y, i;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> y;
        numeros.insert(y);
    }

    x = numeros.size();
    for (i = 1; i <= n; i++)
    {
        numeros.insert(i);
        if (x != numeros.size())
        {
            cout << i << endl;
            break;
        }
    }
}