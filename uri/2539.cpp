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
#define lsb(x) ((x) & (-x))
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long arr[100009], n, ft[100009], x, ans;

long long query(int idx)
{
    long long ans = 0;
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
    while (cin >> n)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ft[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            arr[x] = abs(i - n) + 1;
            update(i, 1);
        }

        for (int i = 1; i <= n; i++)
        {
            ans += query(arr[i] - 1);
            update(arr[i], -1);
        }

        cout << ans << endl;
    }
}