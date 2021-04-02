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

vector<int> grafo[100009];
int vis[100009], pai[100009], n, m, resp, k, a, b, p;

int dfs(int u, int p)
{
    vis[u] = 1;
    if (!resp) pai[u] = p;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (vis[v] && v != p && !resp) resp = u, pai[v] = u;
        if (!vis[v]) dfs(v, u);
    }
    return 1;
}

int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) dfs(i, 0);
        if (resp) break;
    }

    if (!resp)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    k = resp;
    while (pai[k] != resp) ++p, k = pai[k];
    k = resp;
    cout << p + 2 << endl << resp << ' ';
    while (pai[k] != resp)
    {
        cout << pai[k] << ' ';
        k = pai[k];
    }
    cout << resp << endl;
}