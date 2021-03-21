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

int n, a, b, pai[100100], m;
pair<long long, par> arestas[400009];
long long ans, c;

int find(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a), b = find(b);
    pai[a] = b;
}

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++) pai[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        arestas[i] = make_pair(c, par(a, b));
        arestas[i + m] = make_pair(c, par(b, a));
    }

    sort(arestas, arestas+(2*m));

    for (int i = 0; i < 2*m; i++)
    {
        int a = arestas[i].second.first, b = arestas[i].second.second;
        if (find(a) == find(b)) continue;
        ans += arestas[i].first;
        join(a, b);
        n--;
    }

    if (n > 1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}