#include <iostream>
#include <vector>
#include <queue>
#define ii pair<long long, long long>
#define INF 1e15

using namespace std;

long long dist[509][509], n, m, a, b, c, q;

int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = INF;
            dist[j][j] = 0;
        }   

    while (m--)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q--)
    {
        cin >> a >> b;
        cout << (dist[a][b] != INF ? dist[a][b] : -1) << endl;
    }
}