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
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<par> grafo[1<<20];
int t, n, a, b, test, c, end_here[1<<20], sub[1<<20], sum[1<<20];

int f(int u, int p)
{
    int ans = 0, x, s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < grafo[u].size(); i++)
    {
        int v = grafo[u][i].first, w = grafo[u][i].second;
        if (v == p) continue; 
        x = f(v, u);
        sum[u] += sub[v]*i*s1 + s2*i*x + sub[v]*i*s2*(w+s3) + x; 
        s1 += x, s2 += sub[v], s3 += w;
        ans += x + (sub[v]*w);
    }
    sub[u] = s2;
    return end_here[u] = ans;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            sub[i] = 1;
            cin >> a >> b >> c;
            grafo[a].push_back(par(b, c));
            grafo[b].push_back(par(a, c));
        }
        sub[n] = 1;

        f(1, 0);
        for (int i = 1; i <= n; i++)
            cout << sum[i] << endl;
    }
}
