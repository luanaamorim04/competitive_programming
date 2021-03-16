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

int n, a, b, conta, dif, ver[100009];
vector<int> grafo[100009];

void dfs(int u, int pai)
{
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (v != pai)
        {
            dfs(v, u);
            conta = ++ver[v];
            ver[u] += conta;
            dif = min(dif, abs(conta - (n - conta)));
        }
    }
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dif = INF;
    dfs(1, 0);
    cout << dif << endl;
}