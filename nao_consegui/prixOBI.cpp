#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

stack<int> maior, pilha;
int n, m, vis[200001], idx, menor, comp[200001], peso[200001], resp, dist[200001], axm;
vector<par> grafo[200001];

int dfs(int u)
{
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i].first, w = grafo[u][i].second;
        maior.push(max(maior.top(), w));
        if (vis[v]) 
        maior.pop();
    }
}

// void dfs2(int u)
// {
//     vis[u] = 1;
//     comp[u] = idx;
//     peso[idx] = max(peso[idx], maior.top());
//     for (int i = 0; i < grafo[u].size(); i++)
//     {
//         int v = grafo[u][i].first, w = grafo[u][i].second;
//         maior.push(max(maior.top(), w));
//         if (vis[v])
//         {
//             menor = 
//         }
//         maior.pop();
//     }
// }

int main()
{_
    for (int i = 1; i <= n; i++)
    {
        resp = min(resp, dfs(i));
    }
}