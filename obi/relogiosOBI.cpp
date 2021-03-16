#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 1000000007LL
#define MOD 1000000007
#define par pair<int, int>
#define ii pair<int, par>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long N, M, K, tab[109][109], dist[109][109], tempo;
priority_queue<ii, vector<ii>, greater<ii> > fila;

int main()
{_
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> tab[i][j];
            dist[i][j] = INF;
        }

    fila.push(make_pair(0, make_pair(1, 1)));
    dist[1][1] = 0;

    while (!fila.empty())
    {
        int d = fila.top().first, a = fila.top().second.first, b = fila.top().second.second; fila.pop();
        if (d != dist[a][b]) continue;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i && j) continue;
                if (a + i > N || a + i < 1 || b + j > M || b + j < 1) continue;
                int x = tab[a + i][b + j], y = tab[a][b];
                if (x == -1)
                {
                    tempo = 1;
                }
                else if (y != -1) 
                {
                    if (((d%K) + 1) % K != x) continue;
                    tempo = 1;
                }
                else
                {
                    tempo = (x - (d%K) + K) % K;
                } 

                if (!tempo) tempo = K;

                if (dist[a + i][b + j] > dist[a][b] + tempo)
                {
                    dist[a + i][b + j] = dist[a][b] + tempo;
                    fila.push(make_pair(dist[a + i][b + j], make_pair(a + i, b + j)));
                }
            }
        }
    }

    cout << (dist[N][M] == INF ? -1 : dist[N][M]) << endl;
}