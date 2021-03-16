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

int n, m, grau[101], dp[100009];

int main()
{_  
    while (cin >> n >> m)
    {
        int a, b;
        for (int i = 0; i <= n; i++) grau[i] = 0;
        for (int i = 0; i <= m; i++) dp[i] = 0;

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            grau[a]++;
            grau[b]++;
        }

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= grau[i]; j--)
            {
                dp[j] |= dp[j - grau[i]];
            }
        }

        cout << (dp[m] ? 'S' : 'N') << endl;
    }
}