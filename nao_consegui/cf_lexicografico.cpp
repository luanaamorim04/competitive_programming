#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 2e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

priority_queue<par, vector<par>, greater<par> > fila;
int dist[MAXN], n, m, a, b;
string dist_c[MAXN], resp[MAXN];
char x;
vector<pair<int, char> > grafo[MAXN];

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> x;
        grafo[a].push_back(make_pair(b, x));
        grafo[b].push_back(make_pair(a, x));
    }

    for (int i = 2; i <= n; i++)
        dist[i] = INF;
    
    fila.push(par(0, 1));
    while (!fila.empty())
    {
        int u = fila.top().second, d = fila.top().first; fila.pop();
        if (d != dist[u]) continue;

        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i].first;
            char c = grafo[u][i].second;
            if (dist[v] > d + 1)
            {
                dist[v] = d + 1;
                dist_c[v] = dist_c[u] + c;
                fila.push(par(dist[v], v));
                if (resp[v] != "") resp[v] = ' ' + resp[u] ;
                else resp[v] = resp[u];
                resp[v] += to_string(u);
            }
            else if (dist[v] == d + 1)
            {
                if (dist_c[v] > dist_c[u] + c)
                {
                    dist_c[v] = dist_c[u] + c;
                    fila.push(par(d, v));
                    if (resp[v] != "") resp[v] = resp[u] + ' ';
                    else resp[v] = resp[u];
                    resp[v] += to_string(u);
                }
            }
        }
    }

    cout << dist[n] << endl;
    cout << resp[n] << endl;
    cout << dist_c[n] << endl;
}