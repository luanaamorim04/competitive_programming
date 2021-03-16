#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, h[220], a, b, memo[220], ans;
vector<int> grafo[220];

int f(int u)
{
    if (memo[u] != -1) return memo[u];
    int ans = 0;

    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (h[u] > h[v]) ans = max(ans, f(v) + 1);
    }

    return memo[u] = ans;
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        memo[i] = -1;
    }

    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    cout << f(s) << endl;
}
    