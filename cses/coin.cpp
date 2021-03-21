#include <iostream>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{_
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b && a % 3 == 0) cout << "YES" << endl;
        else if (a == b) cout << "NO" << endl;
        else
        {
            if (a > b) swap(a, b);
            
            cout << ((a == (b/2) + 2*(b % 2)) ? "YES" : "NO") << endl;
        }
    }
}