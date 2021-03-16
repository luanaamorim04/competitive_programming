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

vector<int> grafo[MAXN];
long long n, ans, a, b, c, passou[MAXN], k;

void dfs(int u)
{
    passou[u] = 1;
    k++;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (!passou[v]) dfs(v);
    }
}

int main()
{_  
    cin >> n;
    ans = n  * (n - 1) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        if (!c)
        {
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!passou[i]) 
        {
            k = 0;
            dfs(i);
            ans -= (k * (k - 1) / 2);
        }
    }

    cout << ans << endl;
}