#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m, dist[2001], p[2001];

int main()
{
    cin >> t;
    while (t--)
    {
        int ok = 0;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> p[i];

        sort(p, p+n);

        if (p[n - 1] <= m || p[0] + p[1] <= m) ok = 1;

        cout << (ok ? "YES" : "NO") << endl;
    }
}