#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int e[MAXN], d[MAXN], ft[MAXN], n, a[MAXN], copia[MAXN], resp, idx;
map<int, int> mapa;
set<int> val;

int query(int idx)
{
    int ans = 0;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        copia[i - 1] = a[i];
    }

    sort(copia, copia+n);

    for (int i = 0; i < n; i++)
        mapa[copia[i]] = i + 1;

    for (int i = n; i >= 1; i--)
    {
        e[i] = query(mapa[a[i]] - 1);
        update(mapa[a[i]], e[i] + 1);
    }

    for (int i = n; i >= 0; i--)
        ft[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        d[i] = query(mapa[a[i]] - 1);
        resp = max(resp, min(d[i], e[i]) + 1);
        update(mapa[a[i]], d[i] + 1);
    }

    cout << resp * 2 - 1 << endl;
}