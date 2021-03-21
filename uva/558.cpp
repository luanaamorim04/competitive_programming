#include <iostream>
#include <cstring>

using namespace std;

int t, n, m, dist[2001], p[2001];
pair<int, int> a[2001];

int main()
{
    cin >> t;
    while (t--)
    {
        int ok = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i].first >> a[i].second >> p[i];

        memset(dist, 0, sizeof(dist));

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m; j++)
                dist[a[j].second] = min(dist[a[j].second], dist[a[j].first] + p[j]);

        for (int j = 0; j < m; j++)
            if (dist[a[j].second] > dist[a[j].first] + p[j]) ok = 1;

        cout << (ok ? "possible" : "not possible") << endl;
    }
}