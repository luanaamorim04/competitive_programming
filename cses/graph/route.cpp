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
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int nivel[100009], n, m, pai[100009];
vector<int> grafo[100009];
queue<int> fila;

void path(int u)
{
    if (u != 1) path(pai[u]);
    cout << u << ' ';
}

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    nivel[1] = 1;
    fila.push(1);
    while (!fila.empty())
    {
        int u = fila.front(); fila.pop();
        for (int i = 0; i < grafo[u].size(); i++)
        {
            int v = grafo[u][i];
            if (!nivel[v])
            {
                nivel[v] = nivel[u] + 1;
                pai[v] = u;
                fila.push(v);
            }
        }
    }

    if (!nivel[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << nivel[n] << endl;
    path(n);
    cout << endl;
}