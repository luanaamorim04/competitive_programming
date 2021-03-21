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

int n, tab[301][301];
int memo[301][301];

int f(int a, int b)
{
    if (a < 0 || b < 0 || a >= n || b >= n) return INF;
    if (!a && !b) return tab[a][b];
    if (memo[a][b] != -1) return memo[a][b];
    memo[a][b] = INF;
    int ans = f(a + 1, b); ans = min(ans, f(a - 1, b)); ans = min(ans, f(a, b + 1)); ans = min(ans, f(a, b - 1));
    return memo[a][b] = max(ans, tab[a][b]);
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> tab[i][j];
            memo[i][j] = -1;
        }

    cout << f(n - 1, n - 1) << endl;
}