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

int n, arr[500009], ft[500009], x;

void update(int idx, int val)
{
    while (idx <= n)
    {
        ft[idx] += val;
        idx += lsb(idx);
    }
}

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

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << query(arr[i]);
        if (i != n) cout << ' ';
        update(arr[i], -1);
    }
    cout << endl;
}