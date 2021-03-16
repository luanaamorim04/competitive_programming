#include <bits/stdc++.h>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> g1[MAXN], g2[MAXN], dag[MAXN];
stack<int> pilha;
int n, m, a, b, comp[100009],passou[MAXN];
vector<pair<int, int> >arestas;

void dfs(int u)
{
    passou[u] = 1;
    for (int i = 0; i < g1[u].size(); i++)
    {
        int v = g1[u][i];
        if (!passou[v]) dfs(v);
    }
    pilha.push(u);
}

void scc(int u, int k)
{
    passou[u] = 1;
    comp[u] = k;
    for (int i = 0; i < g2[u].size(); i++)
    {
        int v = g2[u][i];
        if (!passou[v]) scc(v, k);
    }
}

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
        arestas.push_back(make_pair(a, b));
    }

    dfs(1);
    int k = 0;
    memset(passou, 0, sizeof(passou));
    while (!pilha.empty())
    {
        int p = pilha.top(); pilha.pop();
        if (!comp[p]) scc(p,  ++k);
    }
    
    for (int i = 0; i < arestas.size(); i++)
    {
        if (comp[arestas[i].first] != comp[arestas[i].second])
            dag[comp[arestas[i].first]].push_back(comp[arestas[i].second]);
    }

    for (int i = 1; i <= k; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < dag[i].size(); j++)
            cout << dag[i][j] << ' ';
        cout << endl;
    }

}