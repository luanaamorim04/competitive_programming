#include <iostream>
#include <cstring>

using namespace std;

int t, n, m, dist[2001], p[2001];
pair<int, int> a[2001];

int bellman(int x)
{
    memset(dist, 0, sizeof(dist));

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            dist[a[j].second] = min(dist[a[j].second], dist[a[j].first] + p[j] - x);

    for (int j = 0; j < m; j++)
        if (dist[a[j].second] > dist[a[j].first] + p[j] - x) return 1;

    return 0;
}

int main()
{
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int ok = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i].first >> a[i].second >> p[i]; 

        int ini = 1, fim = 10000000, meio;
        while (ini + fim <= (1e-2))
        {
            meio = ini + (fim - ini)/2;
            if (bellman(meio)) fim = meio - 1;
            else ini = meio + 1;
        }

        cout << "Case #" << k << ": " << fim + 1 << endl;
    }
}