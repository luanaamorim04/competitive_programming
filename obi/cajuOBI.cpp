#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long l, c, m, n, x, psa[1001][1001], ans;

int main()
{_
    cin >> l >> c >> m >> n;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> x;
            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1] + x;
            if (i >= m && j >= n)
                ans = max(ans, (psa[i][j] - psa[i - m][j] - psa[i][j - n] + psa[i - m][j - n]));
        }
    
    cout << ans << endl;
}