#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[100009];
int dist[100009], ans, n, a, b;

void dfs(int u, int p)
{
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (v != p) dfs(v, u); 
    }

    if (dist[p])
    {
        ans = min(ans, dist[u] + 1 + dist[p]);
        dist[p] = min(dist[p], dist[u] + 1);
    } 
    else dist[p] = dist[u] + 1;

    if (grafo[u].size() == 1 && dist[u]) ans = min(ans, dist[u]);
}

int main()
{_
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    ans = INF;
    dfs(1, 0);

    cout << ans << endl;
}