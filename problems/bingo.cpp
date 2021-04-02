#include <iostream>
#include <set>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> numeros;

int main()
{_
    int n, b, arr[100], ok, i;
    while (cin >> n >> b && b)
    {
        ok = 1;
        for (i = 0; i < b; i++)
            cin >> arr[i];

        for (i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
                if (j != i)
                    numeros.insert(max(arr[i], arr[j]) - min(arr[i], arr[j]));

        int x = numeros.size();
        for (i = 1; i <= n; i++)
        {
            numeros.insert(i);
            if (x != numeros.size())
            {
                ok = 0;
                break;
            }
        }

        cout << (ok ? 'Y' : 'N') << '\n';
        numeros.clear();
    }
}