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

int passou[100009], n, m, last;
vector<int> grafo[100009];
vector<par> arestas;

void flood(int u)
{
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!passou[v])
        {
            passou[v] = 1;
            flood(v);
        }
    }
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

    for (int i = 1; i <= n; i++)
        if (!passou[i])
        {
            passou[i] = 1;
            if (last) arestas.push_back(par(last, i));
            flood(i);
            last = i;
        }

    cout << arestas.size() << endl;
    for (int i = 0; i < arestas.size(); i++)
        cout << arestas[i].first << ' ' << arestas[i].second << endl;
}