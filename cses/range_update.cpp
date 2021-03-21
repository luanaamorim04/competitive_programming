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

ll ft[1<<20], n, q, a, b, k, x, m;

ll query(int idx)
{
    ll ans = 0;
    while (idx > 0)
    {
        ans += ft[idx];
        idx -= lsb(idx);
    }
    return ans;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] += val;
        idx += lsb(idx);
    }
}

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        update(i, x - query(i));
    }
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> a >> b >> k;
            update(a, k);
            update(b + 1, -k);
        }
        else
        {
            cin >> a;
            cout << query(a) << endl;
        }
    }
}
