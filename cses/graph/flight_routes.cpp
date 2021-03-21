#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int vis[100009], n, m, a, b, ans, x, y;
vector<int> grafo[100009], g[100009];
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
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!vis[v]) scc(v);
    }
}

int main()
{
    cin >> n >> m;
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
            x = (x ? x : s.top());
            y = s.top();
            ans++;
        }
        scc(s.top());
        s.pop();
    }

    if (ans != 1)
    {
        cout << "NO\n";
        cout << y << ' ' << x << endl;
    }
    else
    {
        cout << "YES\n";
    }
    
}