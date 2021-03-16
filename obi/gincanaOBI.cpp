#include <iostream>
#include <vector>

#define MAXN 50050

using namespace std;

vector<int> amizades[MAXN];
int componente[MAXN];
int m, n;

void dfs(int x)
{
    for(int i = 0; i < (int)amizades[x].size(); i++)
    {
		int v = amizades[x][i];
		if(componente[v] == -1)
        { 
			componente[v] = 0;
			dfs(v);
		}
	}
}

int main()
{
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) componente[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        amizades[a].push_back(b);
        amizades[b].push_back(a);
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (componente[i] == -1)
        {
            res++;
            componente[i] = 0;
			dfs(i);
        }
    }

    std::cout << res << endl;
}