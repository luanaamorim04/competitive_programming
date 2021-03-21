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

int team[100009], n, m;
vector<int> grafo[100009];
queue<int> fila;

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

    for (int i = 1; i <= n; i++)
    {
        if (team[i]) continue;
        team[i] = 1;
        fila.push(i);
        while (!fila.empty())
        {
            int u = fila.front(); fila.pop();
            for (int i = 0; i < grafo[u].size(); i++)
            {
                int v = grafo[u][i];
                if (!team[v])
                {
                    team[v] = team[u]*-1;
                    fila.push(v);
                }
                else if (team[v] != team[u]*-1)
                {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (team[i] < 0 ? 2 : 1) << ' ';
    }
}