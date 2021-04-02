#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define mp make_pair
#define par pair<pair<int, int>, pair<int, int> >
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, K, vis[1001][1001][5], a, b, c, d;
deque<par> fila;
char tab[1001][1001];

void direita(int a, int b, int k, int dir)
{
    if (b + 1 == m) return;
    if (dir == 1 && vis[a][b + 1][dir] > vis[a][b][dir] && k < K) 
    {
        fila.push_front(mp(mp(a, b + 1), mp(k + 1, 1)));
        vis[a][b + 1][dir] = vis[a][b][dir];
    }
    else if (vis[a][b + 1][1] > vis[a][b][dir] + 1)
    {
        fila.push_back(mp(mp(a, b + 1), mp(1, 1)));
        vis[a][b + 1][1] = vis[a][b][dir] + 1;
    }
}

void esquerda(int a, int b, int k, int dir)
{
    if (!b) return;
    if (dir == 2 && vis[a][b - 1][dir] > vis[a][b][dir] && k < K) 
    {
        fila.push_front(mp(mp(a, b - 1), mp(k + 1, 2)));
        vis[a][b - 1][dir] = vis[a][b][dir];
    }
    else if (vis[a][b - 1][2] > vis[a][b][dir] + 1)
    {
        fila.push_back(mp(mp(a, b - 1), mp(1, 2)));
        vis[a][b - 1][2] = vis[a][b][dir] + 1;
    }
}

void cima(int a, int b, int k, int dir)
{
    if (!a) return;
    if (dir == 3 && vis[a - 1][b][3] > vis[a][b][dir] && k < K) 
    {
        fila.push_front(mp(mp(a - 1, b), mp(k + 1, 3)));
        vis[a - 1][b][3] = vis[a][b][dir];
    }
    else if (vis[a - 1][b][3] > vis[a][b][dir] + 1)
    {
        fila.push_back(mp(mp(a - 1, b), mp(1, 3)));
        vis[a - 1][b][3] = vis[a][b][dir] + 1;
    }
}

void baixo(int a, int b, int k, int dir)
{
    if (a + 1 == n) return;
    if (dir == 4 && vis[a + 1][b][dir] > vis[a][b][dir] && k < K) 
    {
        fila.push_front(mp(mp(a + 1, b), mp(k + 1, 4)));
        vis[a + 1][b][dir] = vis[a][b][dir];
    }
    else if (vis[a + 1][b][4] > vis[a][b][dir] + 1)
    {
        fila.push_back(mp(mp(a + 1, b), mp(1, 4)));
        vis[a + 1][b][4] = vis[a][b][dir] + 1;
    }
}

int main()
{_
    cin >> n >> m >> K;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
            vis[i][j][0] = INF;
            vis[i][j][4] = INF;
            vis[i][j][1] = INF;
            vis[i][j][2] = INF;
            vis[i][j][3] = INF;
        }

    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    vis[a][b][0] = 0;

    fila.push_front(mp(mp(a, b), mp(0, 0)));
    while (!fila.empty())
    {
        int a = fila.front().first.first, b = fila.front().first.second,
        k = fila.front().second.first, dir = fila.front().second.second; fila.pop_front();
        if (tab[a][b] == '#') continue;
        direita(a, b, k, dir);
        baixo(a, b, k, dir);
        esquerda(a, b, k, dir);
        cima(a, b, k, dir);
        //cout << a << ' ' << b << ' ' << k << " dir: " << dir << " custo: " << vis[a][b][dir] <<  endl;
    }

    int ans = INF;
    for (int i = 0; i < 5; i++)
        ans = min(ans, vis[c][d][i]);
    cout << (ans == INF ? -1 : ans) << endl;
}