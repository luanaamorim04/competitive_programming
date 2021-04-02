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

vector<int> grafo[1<<20], v;
int n, q, a, b, pos[1<<20], filho[1<<20];

int dfs(int u)
{
    v.push_back(u);
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        filho[u] += dfs(v) + 1;
    }
    return filho[u];
}

int main()
{_
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        grafo[a].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < n; i++) pos[v[i]] = i;

    while (q--)
    {
        cin >> a >> b;
        cout << (b <= filho[a] + 1 ? v[pos[a] + b - 1] : -1) << endl;
    }
}
