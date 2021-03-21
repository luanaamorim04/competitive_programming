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

int n, a, b, pai[100100], m, ans, tam[100001], comp, maxn;

int find(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return;
    pai[a] = b;
    tam[b] += tam[a];
    maxn = max(maxn, tam[b]);
}

int main()
{_  
    cin >> n >> m;
    comp = n;
    for (int i = 1; i <= n; i++) 
    {
        pai[i] = i;
        tam[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (find(a) != find(b)) comp--;
        join(a, b);
        cout << comp << ' ' << maxn << endl;
    }
}