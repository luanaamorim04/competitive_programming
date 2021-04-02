#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<20];
int n, m, passou[1<<20], a, b, cor[1<<20], resp[2], t, x;

void dfs(int u)
{
    passou[u] = x;
    ++resp[cor[u]];
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (passou[v] == x) continue;
        cor[v] = cor[u]^1;
        dfs(v);
    }
}

int main()
{_
    cin >> t;
    for (x = 1; x <= t; x++)
    {
        cin >> n >> m;
        while (m--)
        {
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        dfs(1);
        cout << min(resp[0], resp[1]) << endl;
        int k = resp[0] < resp[1] ? 0 : 1;
        for (int i = 1; i <= n; i++) 
        {
            if (cor[i] == k) cout << i << ' '; 
            grafo[i].clear();
        }
        cout << endl;
        resp[0] = resp[1] = 0;
    }
}
