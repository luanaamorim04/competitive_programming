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

int n, a, b, nivel[1000001], ans;
vector<int> grafo[1000001];
queue<int> fila;

int bfs(int x)
{
    fila.push(x);
    nivel[x] = 1;
    int k;
    memset(nivel, 0, sizeof(nivel));
    while (!fila.empty())
    {
        int u = fila.front(); fila.pop();
        if (nivel[u] > ans)
        {
            ans = nivel[u];
            k = u;
        }
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            if (!nivel[v])
            {
                nivel[v] = nivel[u] + 1;
                fila.push(v);
            }
        }
    }

    return k;
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int u = bfs(1);
    bfs(u);
    cout << ans << endl;
}