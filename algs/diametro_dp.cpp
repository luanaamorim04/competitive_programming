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
queue<int> fila;
int n, memo[1<<20], resp, a, b, pai[1<<20], filho[1<<20];

int f(int u, int p)
{
    if (~memo[u]) return memo[u];
    pai[u] = p;
    int ans = 0;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if (v == p) continue;
        if (ans < f(v, u) + 1) ans = f(v, u) + 1;
    }
    return memo[u] = ans;
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
    memset(memo, -1, sizeof(memo));
    f(1, 0);

    for (int i = 1; i <= n; i++)
    {
        int a = -1, b = -1;
        for (int j = 0; j < grafo[i].size(); j++)
        {
            int v = grafo[i][j];
            if (v == pai[i]) continue;
            if (a > b) swap(a, b);
            if (memo[v] > a) a = memo[v];
        }
        resp = max(resp, a + b + 2);
    }
    cout << resp << endl;
}    
