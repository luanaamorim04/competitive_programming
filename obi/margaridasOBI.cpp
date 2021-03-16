#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, c, l, psa[1009][1009], ans;

int main()
{_
    cin >> n >> m >> c >> l;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> psa[i][j];
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }

    for (int i = c; i <= n; i += c)
        for (int j = l; j <= m; j += l)
        {
            ans = max(ans, psa[i][j] - psa[i - c][j] - psa[i][j - l] + psa[i - c][j - l]);
        }

    if (ans > 1000000) ans = 1000000;
    cout << ans << endl;
}