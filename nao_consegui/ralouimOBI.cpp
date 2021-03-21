#include <iostream>
#define MAXN 1000000001LL
#define dist(x1, x2, y1, y2) (long long) ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))

using namespace std;

int n, x[2001], y[2001], idx[2001][2001], k, ans;
long long grafo[2001][2001], achar[2001][2001];

int ordenar(int a, int b)
{
    return grafo[k][a] < grafo[k][b];
}

int bb(int u, int p)
{
    int ini = 1, fim = n, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (grafo[u][meio] < achar[u][p]) ini = meio + 1;
        else fim = meio - 1;
    }
    
    if (ini == 1) return -1;
    return idx[u][ini - 1];
}

int f(int u, int p)
{
    //cout << u << ' ';
    if (bb(u, p) == -1) return 0;
    return f(bb(u, p), u) + 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            grafo[k][j] = dist(x[k], x[j], y[k], y[j]);
            achar[k][j] = grafo[k][j];
            idx[k][j] = j;
        }
        achar[k][0] = dist(0, x[k], 0, y[k]);
        grafo[k][k] = MAXN;
        sort(idx[k]+1, idx[k]+n+1, ordenar);
        sort(grafo[k]+1, grafo[k]+n+1);
    }

    // cout << "\ndistancias: ";
    // for (k = 1; k <= n; k++)
    //     cout << achar[1][k] << ' ';
    // cout << "\ndistancias sorted: ";
    // for (k = 1; k <= n; k++)
    //     cout << grafo[1][k] << ' ';
    // cout << "\nindices: ";
    // for (k = 1; k <= n; k++)
    //     cout << idx[1][k] << ' ';
    // cout << endl;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f(i, 0));
    }

    cout << ans << endl;
}