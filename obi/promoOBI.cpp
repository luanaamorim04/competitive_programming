#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, c, memo[500009][3], pai[500009], k;
vector<par> grafo[50009];

int f(int x, int last)
{
    int ans = 1;
    if (memo[x][last] != -1) return memo[x][last];
    for (int i = 0; i < grafo[x].size(); i++)
    {
        int v = grafo[x][i].first, w = grafo[x][i].second;
        if (w != last) ans = max(ans, f(v, w) + 1);
    }

    return memo[x][last] = ans;
}

int main()
{_
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
        for (int j = 0; j < 3; j++)
            memo[i][j] = -1;
    }

    for (int j = 0; j < 3; j++)
        memo[n][j] = -1;

    for (int i = 1; i < n; i++)
        k = max(k, f(i, 2));

    cout << k << endl;
}