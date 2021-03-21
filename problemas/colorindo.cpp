#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[208][208], x , y, k, a, b, ans;

void dfs(int a, int b)
{
    if (a < 1 || b < 1 || a > n || b > m) return;
    if (tab[a][b] == -1) return;
    tab[a][b] = -1;
    ans++;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            dfs(a + i, b + j);
}

int main()
{_
    cin >> n >> m >> x >> y >> k;
    while (k--)
    {
        cin >> a >> b;
        tab[a][b] = -1;
    }

    dfs(x, y);
    cout << ans << endl;
}