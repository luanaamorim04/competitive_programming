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

int n, a, b, memo[100009][2], pode[100009];
vector<int> grafo[100090];

int f(int u, int pai)
{
    if (memo[u][pai] != -1) return memo[u][pai];

    pode[u] = 1;
    int ans = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (pode[v]) continue;
        if (!pai) ans = (ans * (f(v, 1) * f(v, 0))) % MOD;
        else ans = (ans * f(v, 0));
    }
    pode[u] = 0;

    if (!ans) return memo[u][pai] = (pai ? 1 : 2);
    return memo[u][pai] = ans;
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 0; i <= n; i++)
        memo[i][0] = -1, memo[i][1] = -1;

    cout << f(1, 0) << endl;
}