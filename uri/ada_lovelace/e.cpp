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
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, dist[20], d;
vector<par> grafo[20];
vector<int> last[20];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{
    while (cin >> n >> m && n)
    {
        for (int i = 0; i <= n; i++)
        {
            last[i].clear();
            grafo[i].clear();
            dist[i] = INF;
        }

        while (m--)
        {   
            cin >> a >> b >> c;
            grafo[a].push_back(make_pair(b, c));
            grafo[b].push_back(make_pair(a, c));
        }

        cin >> d;

        fila.push(make_pair(0, 1));
        dist[1] = 0;
        while (!fila.empty())   
        {
            int p = fila.top().first, u = fila.top().second; fila.pop();
            if (dist[u] != p) continue;
            for (int i = 0; i < grafo[u].size(); i++)
            {
                int v = grafo[u][i].first;
                int w = grafo[u][i].second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    last[v] = last[u];
                    last[v].push_back(u);
                    fila.push(make_pair(dist[v], v));
                }
            }
        }

        if (dist[d] > 120) cout << "It will be " << dist[d] - 120 << " minutes late. ";
        else cout << "Will not be late. ";
        cout << "Travel time - " << dist[d] << " - best way - " << d << ' ';

        for (int i = last[d].size() - 1; i >= 0; i--)
        {
            cout << last[d][i];
            if (i > 0) cout << ' ';
        }

        cout << endl;
    }
}