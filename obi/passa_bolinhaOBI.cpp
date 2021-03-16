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

int tab[1009][1009], n, m, a, b, ans, passou[1009][109];

void flood(int a, int b)
{
    if (passou[a][b]) return;
    passou[a][b] = 1;
    if (tab[a + 1][b] >= tab[a][b]) flood(a + 1, b);
    if (tab[a - 1][b] >= tab[a][b]) flood(a - 1, b);
    if (tab[a][b + 1] >= tab[a][b]) flood(a, b + 1);
    if (tab[a][b - 1] >= tab[a][b]) flood(a, b - 1);
    tab[a][b] = -1;
}

int main()
{_  
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> tab[i][j];

    flood(a, b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += (tab[i][j] == -1);

    cout << ans << endl;
}   