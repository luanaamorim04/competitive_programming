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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, passou[1<<20], pai[1<<20], ciclo, resp;
vector<int> grafo[1<<20];

void dfs(int u)
{
    passou[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        if (ciclo) continue;
        int v = grafo[u][i];
        pai[v] = u;
        if (passou[v] == 1) ciclo = u, pai[v] = 0;
        else if (!passou[v]) dfs(v);
    }
    passou[u] = 2;
}

void f(int x)
{
    if (!x) return;
    f(pai[x]);
    cout << x << ' ';
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
        if (!passou[i]) dfs(i);

    if (!ciclo)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int x = pai[ciclo];
    while (x)
    {
        ++resp;
        x = pai[x];
    }
    cout << resp + 2 << endl << ciclo << ' ';
    f(ciclo);
    cout << endl;
}
