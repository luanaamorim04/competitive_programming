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

int tin[MAXN], tout[MAXN], timer, up[MAXN][22];
long long dist[MAXN];
int a, b, c, n, s, t, q;
vector<par> grafo[MAXN];

void dfs(int u, int p)
{
    tin[u] = ++timer;
    up[u][0] = p;

    for (int i = 1; i < 21; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i].first;
        if (v != p) 
        {
            dist[v] = dist[u] + grafo[u][i].second;
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

int is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int LCA(int u, int v)
{
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;

    for (int i = 20; i >= 0; i--)
    {
        if (!is_anc(up[v][i], u))
        {
            v = up[v][i];
        }
    }

    return up[v][0];
}

int main()
{_  
    while (cin >> n && n)
    {
        for (int i = 0; i <= n; i++)
        {
            dist[i] = 0;
            grafo[i].clear();
            timer = 0;
            for (int j = 0; j < 21; j++)
                up[i][j] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(make_pair(i, b));
            grafo[i].push_back(make_pair(a, b));
        }

        dfs(0, 0);

        cin >> q;
        while (q--)
        {
            cin >> s >> t;
            cout << dist[s] + dist[t] - 2*dist[LCA(s, t)] << ' ';
        }

        cout << endl;
    }
}