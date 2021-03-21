#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int vis[100009], n, m, a, b, ans, x, y, p[100009], k, peso[100009];
vector<int> grafo[100009], g[100009], c[100009];
stack<int> s;

void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!vis[v]) dfs(v);
    }
    s.push(u);
}

void scc(int u)
{
    peso[k] += p[u];
    p[u] = k;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!vis[v]) scc(v);
    }
}

int dp(int u, int p)
{
    int ans = 0;
    for (int i = 0; i < c[u].size(); i++)
    {
        int v = c[u][i];
        if (v != p)
            ans = max(ans, dp(v, u) + peso[v]);
    }
    return ans;
}

void compress(int u, int pai)
{
    if (p[pai] != p[u]) c[p[pai]].push_back(p[u]);
    vis[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!vis[v]) compress(v, u);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);

    memset(vis, 0, sizeof(vis));

    while (!s.empty())
    {
        if (!vis[s.top()]) 
        {
            ++k;
            scc(s.top());
        }
        s.pop();
    }

    memset(vis, 0, sizeof(vis));
    compress(1, 0);

    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans = max(ans, dp(i, 0));

    cout << ans << endl;
}