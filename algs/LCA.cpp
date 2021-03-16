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
#define lsb(x) ((x) & (-x))
#define MAX (int) 5e4 + 9
#define L 22
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int timer, tin[MAX], tout[MAX], up[MAX][L], n, x, a, b;
vector<int> grafo[MAX];
par carta[MAX];

void dfs(int u, int p)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < L; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (v != p) dfs(v, u);
    }

    tout[u] = ++timer;
}

int is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v)
{
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;

    for (int i = 21; i >= 0; i--)
    {
        if (!is_anc(up[v][i], u))
        {
            v = up[v][i];
        }
    }

    return up[v][0];
}

int main()
{
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(1, 1);

    while (cin >> a >> b)
    {
        cout << LCA(a, b) << endl;
    }
}