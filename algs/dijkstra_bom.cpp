#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 20000
#define INF 999999999999999999
#define par pair<long long, long long>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<par> grafo[MAX];
priority_queue<par, vector<par>, greater<par> > pq;
long long n, m, N, s, U, dist[MAX], a, b, c, v, w, d, u, teste;

int main()
{_
    cin >> N;
    while (N--)
    {
        cin >> n >> m >> s >> U;
        cout << "Case #" << ++teste << ": ";

        pq.push(make_pair(0, s));

        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;
            if (grafo[i].size()) grafo[i].clear();
        }

        dist[s] = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            grafo[a].push_back(make_pair(b, c));
            grafo[b].push_back(make_pair(a, c));
        }
        
        while (!pq.empty())
        {
            d = pq.top().first, u = pq.top().second; pq.pop();
            if (dist[u] < d) continue;

            for (int i = 0; i < grafo[u].size(); i++)
            {
                v = grafo[u][i].first;
                w = grafo[u][i].second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        if (dist[U] != INF) cout << dist[U] << endl;
        else cout << "unreachable\n";
    }
}