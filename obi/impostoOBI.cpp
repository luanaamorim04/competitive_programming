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
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, cap_max, dist[10009], cap, a, b, c, ans, peso[10009];
vector<par> grafo[10009];
queue<par> fila;

void dfs(int u, int p)
{
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i].first, w = grafo[u][i].second;
        if (v == p) continue;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }

    while (peso[u] > 0)
    {
        peso[p] += min(peso[u], cap_max);
        peso[u] -= cap_max;
        ans += 2*(dist[u] - dist[p]);
    }
}

int main()
{_
    cin >> n >> cap_max;

    for (int i = 1; i <= n; i++)
        cin >> peso[i];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }

    dfs(1, 0);

    cout << ans << endl;
}