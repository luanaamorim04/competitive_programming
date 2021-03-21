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

int n, m, r, k, a, b, pai[1<<18], passou[1<<18];
vector<int> grafo[1<<18], resp;

void dfs(int u)
{
    passou[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!r) pai[v] = u;
        if (passou[v] == 1) r = u;
        else if (!passou[v] && !r) dfs(v);
    }
    passou[u] = 2;
}

int f(int u, int x)
{
    resp.push_back(u);
    if (u == x) return 2;
    return f(pai[u], x) + 1;
}

int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!passou[i] && !r) dfs(i);

    if (!r)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        resp.push_back(r);
        cout << f(pai[r], r) << endl;
        for (int i = 0; i < resp.size(); i++)
            cout << resp[i] << ' ';
        cout << endl;
    }
}
