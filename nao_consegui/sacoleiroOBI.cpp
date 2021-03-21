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

int tipo[33], peso[33], t, n, x, dp[33][101][101];
vector<int> grafo[33];
char c;

int f(int u, int a, int b)
{
    if (a + b > t) return INF;
    if (dp[u][a][b] != -1) return dp[u][a][b];
    dp[u][a][b] = INF;
    cout << u << endl;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        dp[u][a][b] = min(dp[u][a][b], f(v, a, b));
        tipo[v] == 1 ? a += peso[v] : b += peso[v];
        dp[u][a][b] = min(dp[u][a][b], f(v, a, b));
        tipo[v] == 1 ? a -= peso[v] : b -= peso[v];
    }
    if (a || b) return dp[u][a][b] = min(dp[u][a][b], abs(a - b));
    return dp[u][a][b];
}

int main()
{_  
    cin >> n >> t;
    while (n--)
    {
        int k;
        cin >> x;
        cin >> peso[x] >> c >> k;
        c == 'A' ? tipo[x] = 1 : tipo[x] = 2;
        while (k--)
        {
            int y;
            cin >> y;
            grafo[x].push_back(y);
        }
    }

    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                dp[i][j][k] = -1;

    cout << f(0, 0, 0) << endl;
}