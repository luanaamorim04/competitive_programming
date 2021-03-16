#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[10][10], k, a, b, ans;

int main()
{_  
    cin >> n >> m;
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        tab[a][b] = -INF;
        if (tab[a + 1][b] != -INF) tab[a + 1][b] = 1;
        if (tab[a - 1][b] != -INF) tab[a - 1][b] = 1;
        if (tab[a][b + 1] != -INF) tab[a][b + 1] = 1;
        if (tab[a][b - 1] != -INF) tab[a][b - 1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (tab[i][j] <= 0) continue;
            if (tab[i + 1][j] >= 1 && i < n) tab[i][j]++;
            if (tab[i - 1][j] >= 1 && i > 1) tab[i][j]++;
            if (tab[i][j + 1] >= 1 && j < m) tab[i][j]++;
            if (tab[i][j - 1] >= 1 && j > 1) tab[i][j]++;
        }
    }

    for (int k = 5; k >= 2; k--)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (tab[i][j] == k)
                {
                    tab[i][j] = 0;
                    tab[i + 1][j]--;
                    tab[i - 1][j]--;
                    tab[i][j + 1]--;
                    tab[i][j - 1]--;
                }
            
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += (tab[i][j] == 1);
        }
    }

    cout << ans << endl;
}
    