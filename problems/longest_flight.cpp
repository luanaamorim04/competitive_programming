#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, filho[1<<18], memo[1<<18];
vector<int> grafo[1<<18];

int f(int u)
{
    if (~memo[u]) return memo[u];
    if (u == n) return 1;
    int ans = -INF;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (ans <= f(v) + 1)
        {
            filho[u] = v;
            ans = f(v) + 1;
        }
    }

    return memo[u] = ans;
}

int main()
{_
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
    }

    int ans = f(1);
    if (ans < 0) 
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << endl;
    int u = 1;     
    while (u != n)
    {
        cout << u << ' ';
        u = filho[u];
    }
    cout << n << endl;
}