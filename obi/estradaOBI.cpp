#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int t, n, d[10009];
double ini[10009], ans;

int main()
{
    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    ans = 90000000;

    sort(d, d+n);

    for (int i = 1; i < n; i++)
    {   
        ini[i] = d[i - 1] + (d[i] - d[i - 1]) / (double) 2;
        ans = min(ans, ini[i] - ini[i - 1]);
    }

    ans = min(ans, t - ini[n - 1]);

    cout << fixed << setprecision(2) << ans << endl;
}