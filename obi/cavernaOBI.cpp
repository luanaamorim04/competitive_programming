#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n, m, x, last = -1;
    long long res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (min(x, m - x) >= last)
            last = min(x, m - x);
        else if (max(x, m - x) >= last)
            last = max(x, m - x);
        else 
        {
            cout << -1 << "\n";
            return 0;
        }

        res += last;
    }

    cout << res << '\n';


    
}