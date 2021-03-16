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

int n, m, tempo[1009], a, b, c, dist[1009], ans;
vector<par> grafo[1009];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tempo[i];

    while (m--)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
    }

    ans = INF;

    for (int s = 1; s <= n; s++)
    {
        for (int i = 1; i <= n; i++)
            dist[i] = INF;

        fila.push(make_pair(0, s));
        while (!fila.empty())
        {
            int u = fila.top().second, d = fila.top().first; fila.pop();
            if (dist[u] < d) continue;
            for (int i = 0; i < grafo[u].size(); i++)
            {
                int v = grafo[u][i].first, w = grafo[u][i].second;
                if (dist[v] > d + w + tempo[u])
                {
                    dist[v] = d + w + tempo[u];
                    fila.push(make_pair(dist[v], v));
                }
            }
        }
        
        ans = min(ans, dist[s]);
    }

    cout << ans << endl;
}