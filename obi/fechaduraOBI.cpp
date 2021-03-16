#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, x, val[1001];

int main()
{_
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        val[i] = x - k;
    }

    x = 0;
    for (int i = 0; i < n; i++)
    {
        if (!val[i]) continue;

        val[i + 1] -= val[i];
        x += abs(val[i]);
    }

    cout << x << endl;

}