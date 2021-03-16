#include <iostream>
#include <set>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, y, i, ans;

int main()
{_
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> y;
        ans += y;
    }

    cout << ans - n << endl;
}