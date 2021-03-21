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
#define MAXN 100001
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

queue<par> fila;
vector<int> g1[MAXN], g2[MAXN];
int n, m, a, b, n1[MAXN], n2[MAXN], maxd1, maxd2, nivel1[MAXN], nivel2[MAXN], r1[MAXN], r2[MAXN], idx;

void bfs(int x)
{
    fila.push(make_pair(1, 0));
    while (!fila.empty())
    {
        int u = fila.front().first, p = fila.front().second; fila.pop();
        for (int i = 0; i < (x ? g1 : g2)[u].size(); i++)
        {
            int v = (x ? g1 : g2)[u][i];
            if (v == p) continue;
            (x ? n1 : n2)[v] = (x ? n1 : n2)[u] + 1;
            fila.push(make_pair(v, u));
        }
        (x ? maxd1 : maxd2) = u;
    }
}




int meio(int x)
{
    fila.push(make_pair((x ? maxd1 : maxd2), 0));
    while (!fila.empty())
    {
        int u = fila.front().first, p = fila.front().second; fila.pop();
        for (int i = 0; i < (x ? g1 : g2)[u].size(); i++)
        {
            int v = (x ? g1 : g2)[u][i];
            if (v == p) continue;
            (x ? nivel1 : nivel2)[v] = (x ? nivel1 : nivel2)[u] + 1;
            fila.push(make_pair(v, u));
        }
    }
}

void back_track(int u, int x)
{
    cout << u << ' ';
    //(x ? r1 : r2)[idx++] = u;
    if ((x ? b1 : b2)[u]) return back_track((x ? b1 : b2)[u], x);
    else return;
}

int main()
{_
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }

    for (int i = 1; i < m; i++)
    {
        cin >> a >> b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    bfs(1), bfs(0);
    meio(1), meio(0);
    back_track(1, 1);
    // if (n1[r1[idx/2]] > n1[r1[idx - (idx/2)]]) cout << r1[idx/2] << ' ';
    // else cout << r1[idx - (idx/2)] << ' ';
    // idx = 0;
    cout << endl;
    cout << n1[maxd1] << endl;
    back_track(1, 0);
    // if (n2[r2[idx/2]] > n2[r2[idx - (idx/2)]]) cout << r2[idx/2] << '\n';
    // else cout << r2[idx - (idx/2)] << '\n';
    cout << endl;
    cout << n2[maxd2] << endl;
}