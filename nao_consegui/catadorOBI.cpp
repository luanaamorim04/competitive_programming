#include <iostream>
#define lsb(x) ((x) & (-x))

using namespace std;

int n, m, arr[100001], ft[100011], x, ans;

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
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (m--)
    {
        cin >> x;
        int k = query(x) - query(x - 1);
        int esq = max(1, x - k);
        int dir = min(n, x + k) + 1;
        cout << esq << ' ' << dir << endl;
        update(esq, -1);
        update(dir, 1);
    }

    cout << query(n - 1) << endl;
}