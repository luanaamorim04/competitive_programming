#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <unordered_map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e6 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, ft[MAXN], arr[MAXN];
unordered_map<int, int> mapa;

int query(int idx)
{
    int ans = 1;
    while (idx > 0)
    {
        ans = max(ans, ft[idx]);
        idx -= lsb(idx);
    }
    return ans;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] = max(ft[idx], val);
        idx += lsb(idx);
    }
}

int main()
{_  
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        mapa[k] = i;
    }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        k = mapa[k];
        if (!k) continue;
        ans = max(ans, query(k));
        update(k + 1, query(k) + 1);
    }

    cout << ans << endl;
}