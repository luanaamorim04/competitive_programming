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

int tempo, n, p[909], v[909], dp[909][909], memo[909][909];

int f(int peso, int id)
{
    if (peso < 0 || id > n) return -INF;
    int ans = 0;
    if (memo[peso][id] != -1) return memo[peso][id];
    for (int i = 1; i <= n; i++)
        ans = max(ans, f(peso-p[i], i + 1) + v[i]);

    return memo[peso][id] = ans;
}

int main()
{_
    while (cin >> n >> tempo && n)
    {
        for (int i = 1; i <= n; i++)
            cin >> p[i] >> v[i];

        for (int i = 0; i <= tempo; i++)
            for (int j = 1; j <= n; j++)
                memo[i][j] = -1;

        for (int j = tempo; j >= 0; j--)
            for (int i = 1; i <= n; i++)
                if (j >= p[i])
                    dp[j][i] = max(dp[j][i], dp[j - p[i]][i] + v[i]);

        cout << f(tempo, 1) << endl;
    }
}