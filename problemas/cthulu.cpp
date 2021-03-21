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

int a, b, n, m, ok, passou[1<<20];
vector<int> grafo[1<<20];

void dfs(int u)
{
    passou[u] = 1;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!passou[v]) dfs(v);
    }
}

int main()
{_
    cin >> n >> m;
    if (n != m) ok = 1;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (!passou[i]) ok = 1;
    }

    cout << (!ok ? "FHTAGN!" : "NO") << endl;
}
