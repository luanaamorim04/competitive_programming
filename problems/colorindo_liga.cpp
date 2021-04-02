#include <iostream>
#include <vector>
#include <map>
#define MAX 1000000

using namespace std;

int ans, passou[MAX], cor[MAX], n, a, b, ok;
vector<int> grafo[MAX];

void dfs(int x)
{
    if (passou[x] == 1 || cor[x] == 0) return;
    ans += cor[x];
    passou[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++)
    {
        int v = grafo[x][i];
        if (cor[v] == cor[x]) ok = 1;
        cor[v] = cor[x] * -1;
        dfs(v);
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    cor[a] = -1;
    cor[b] = 1;
    dfs(a);

    if (ok == 0 && ans == 0) 
        cout << 'Y';
    else
        cout << 'N';
}