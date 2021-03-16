#include <iostream>
#include <cstring>
#define ll long long
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[1<<20];
ll ft[1<<20], vall[1<<20], resp, val, ans, ft1[1<<20];

void update(int idx, ll val)
{
    while (idx <= n)
    {
        ft[idx] += val;
        idx += lsb(idx);
    }
}

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

int main()
{_
    while (cin >> n)
    {
        resp = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            ft[i] = ft1[i] = 0;
        }

        for (int i = n; i >= 1; i--)
        {
            int idx = arr[i] + 1;
            val = 1;
            while (idx <= n)
            {
                ft[idx] += val;
                idx += lsb(idx);
            }
            idx = arr[i];
            ans = 0;
            while (idx > 0)
            {
                ans += ft[idx];
                idx -= lsb(idx);
            }
            vall[arr[i]] = ans;
        }

        for (int i = n; i >= 1; i--)
        {
            int idx = arr[i] + 1;
            val = vall[arr[i]];
            while (idx <= n)
            {
                ft1[idx] += val;
                idx += lsb(idx);
            }
            idx = arr[i];
            ans = 0;
            while (idx > 0)
            {
                ans += ft1[idx];
                idx -= lsb(idx);
            }
            resp += ans;
        }

        cout << resp << '\n';   
    }
}