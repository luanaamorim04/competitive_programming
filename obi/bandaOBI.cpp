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

int n, m, a, b, c, res, ans[30], t, pts[1001][1010];

int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        pts[a][b] = c;
        pts[b][a] = c;
    }

    res = -1;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                t = pts[i][j] + pts[j][k] + pts[i][k];
                if (res < t)
                {
                    res = t;
                    ans[0] = i, ans[1] = j, ans[2] = k;
                }
            }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}