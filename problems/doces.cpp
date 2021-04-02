#include <iostream>
#include <cstring>

using namespace std;

int dp[10001];

int f(int y, int a[], int l)
{
    if (y > l) return 0;
    if (dp[y] == -1)
        dp[y] = max(f(y + 1, a, l), f(y + 2, a, l) + a[y]);

    return dp[y];
}

int main()
{
    while(true)
    {
        int n, m;
        cin >> n >> m;
        int doces[m], dps[n];
        if (n == 0 && m == 0) return 0;

        for (int i = 0; i < n; i++)
        {
            memset (dp, -1, n);
            for (int j = 0; j < m; j++)
            {
                cin >> doces[j];
            }

            dps[i] = f(0, doces, m);
        }

        if (n == 2)
        {
            if (dps[0] > dps[1]) cout << dps[0] << endl;
            else cout << dps[1] << endl;
            continue;
        }

        cout << f(0, dps, n) << endl;
    }
}