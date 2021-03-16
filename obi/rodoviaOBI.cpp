#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, ans, passou[10009], v[10009], ok;
vector<int> grafo[10009];

void dfs(int x)
{
    for (int i = 0; i < grafo[x].size(); i++)
    {
        v[grafo[x][i]] += v[x];
        if (passou[grafo[x][i]] != 2)
        {
            passou[grafo[x][i]]++;
            dfs(grafo[x][i]);
        }
    }
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        v[i] = 1;
        grafo[a].push_back(b);
    }

    passou[1] = 1;
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (v[i] < n) ok = 1;
    }
    cout << (!ok ? 'S' : 'N') << endl;
}