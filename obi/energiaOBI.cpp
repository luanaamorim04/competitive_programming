#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 101

using namespace std;

int n, m, a, b, teste, passou[MAX], ok;
vector<int> grafo[MAX];

void dfs(int x)
{
    passou[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++)
    {
        int v = grafo[x][i];
        if (!passou[v])
        {
            passou[v] = 1;
            dfs(v);
        }
    }
}

int main()
{_
    while (cin >> n >> m && n)
    {
        ok = 1;
        cout << "Teste " << ++teste << endl;
        while (m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        dfs(1);

        for (int i = 1; i <= n; i++)
        {
            grafo[i].clear();
            if (!passou[i]) ok = 0;
            passou[i] = 0;
        }

        cout << (ok ? "normal\n" : "falha\n") << endl;
    }
}
