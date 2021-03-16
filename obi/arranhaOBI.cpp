#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ft[100009], arr[100009], a, b, x, n, q;

int query(int idx)
{
    int ans = 0;
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
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (q--)
    {
        cin >> x;
        if (!x)
        {
            cin >> a >> b;
            update(a, b - arr[a]);
            arr[a] = b;
        }
        else
        {
            cin >> a;
            cout << query(a) << endl;
        }
    }
}   