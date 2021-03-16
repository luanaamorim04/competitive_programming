#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dist[500][500], n, m, p, a, b;

int main()
{_
    cin >> n >> m >> p;
    while (m--)
    {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                if (!dist[i][j]) dist[i][j] = dist[i][k]*dist[k][j];

    while (p--)
    {
        cin >> a >> b;
        cout << (dist[a][b] ? "Lets que lets\n" : "Deu ruim\n");
    }
}