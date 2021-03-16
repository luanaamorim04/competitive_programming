#include <iostream>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, b, a[200009], ans, i;

int main()
{_
    cin >> n >> b;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n);
    int max = n - 1;

    for (i = 0; i <= max; i++)
    {
        if (a[i] + a[max] <= b)
        {
            ans++;
        }
        else
        {
            i--;
            ans++;
        }

        max--;
    }

    cout << ans << endl;
}