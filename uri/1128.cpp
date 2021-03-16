#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#include <string.h>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, p, passou[2001];
vector<int> g1[2001], g2[2001];
stack<int> s;

void dfs(int u)
{
    passou[u] = 1;
    for (int i = 0; i < g1[u].size(); i++)
    {
        int v = g1[u][i];
        if (!passou[v]) dfs(v);
    }

    s.push(u);
}

void scc(int u)
{
    passou[u] = 1;
    for (int i = 0; i < g2[u].size(); i++)
    {
        int v = g2[u][i];
        if (!passou[v]) scc(v);
    }
}

int main()
{_  
    while (cin >> n >> m && n)
    {
        int ans = 0;
        while (m--)
        {
            cin >> a >> b >> p;
            if (p == 1)
            {
                g1[a].push_back(b);
                g2[b].push_back(a);
            }
            else
            {
                g1[a].push_back(b);
                g2[b].push_back(a);
                g2[a].push_back(b);
                g1[b].push_back(a);
            }
        }

        for (int i = 1; i <= n; i++)
            if (!passou[i]) dfs(i);

        memset(passou, 0, sizeof(passou));
        
        while (!s.empty())
        {
            int x = s.top(); s.pop();
            ans += (!passou[x]);
            scc(x);
        }

        cout << (ans == 1 ? 1 : 0) << endl;

        memset(passou, 0, sizeof(passou));
        for (int i = 1; i <= n; i++)
        {
            g1[i].clear();
            g2[i].clear();
        }
    }
}