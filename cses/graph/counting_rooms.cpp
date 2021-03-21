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

int tab[1009][1009], n, m, ans;
char c;

void flood(int a, int b)
{
    if (!tab[a][b]) return;
    tab[a][b] = 0;
    flood(a + 1, b);
    flood(a - 1, b);
    flood(a, b + 1);
    flood(a, b - 1);
}

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            tab[i][j] = (c == '#' ? 0 : 1);
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (tab[i][j])
            {
                ans++;
                flood(i, j);
            }

    cout << ans << endl;
}