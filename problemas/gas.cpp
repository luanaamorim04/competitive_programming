#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long m, l, c, psa[1001][1001], ans, z, tot;
char x;

int main()
{_
    cin >> l >> c;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> x;
            if (x == 'M') x = 0;
            else x = 1;

            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1] + x;
        }

    cin >> m;
    tot = m * m;

    for (int i = m; i <= l; i++)
        for (int j = m; j <= c; j++)
        {
            z = psa[i][j] - psa[i - m][j] - psa[i][j - m] + psa[i - m][j - m];
            if  (z != 0 && z != tot)
                ans = max(ans, (z * 25) + ((tot - z) * 12));
        }
    
    cout << (ans ? ans : -1) << endl;
}