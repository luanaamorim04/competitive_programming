#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <cstring>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int peso[100001], n, x, memo[100001][2];
vector<int> grafo[100001];

int f(int u, int k)
{
    int ans = 0;
    if (~memo[u][k]) return memo[u][k];
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (k^1) ans += max(f(v, 1) + peso[v], f(v, 0));
        else ans += f(v, 0);
    }
    return memo[u][k] = ans;
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> peso[i];

    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        grafo[x].push_back(i);
    }

    memset(memo, -1, sizeof(memo));

    cout << max(f(1, 0), f(1, 1) + peso[1]) << endl;
}