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
#define par pair<int, ll>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<par> grafo[1<<18];
ll composto[1<<18], n, memo[1<<18], resp, a, b, c;

void crivo()
{
    int k = (1<<18) - 1;
    composto[1] = composto[0] = 1;
    for (int i = 2; i <= k; i++)
    {
        if (composto[i]) continue;
        for (int j = 2; j*i <= k; j++)
        {
            composto[j*i] = 1;
        }
    }
}

ll f(int u, int p)
{
    ll ans = 0;
    if (~memo[u]) return memo[u];
    //cout << u << ' ' << p << endl;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        ll v = grafo[u][i].first, w = grafo[u][i].second;
        if (v == p) continue;
        memo[v] = f(v, u);
        resp = max(resp, memo[v]+w+ans);
        ans = max(ans, memo[v] + w);
    }

    return memo[u] = ans;
}

int main()
{_
    cin >> n;
    memset(memo, -1, sizeof(memo));
    crivo();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        if (composto[c]) continue;
        grafo[a].push_back(par(b, c));
        grafo[b].push_back(par(a, c));
    }

    for (int i = 1; i <= n; i++)
    {
        if (memo[i] == -1) f(i, 0);
    }

    cout << resp << endl;

}
