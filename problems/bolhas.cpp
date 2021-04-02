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

int n, arr[300009], ft[300009], ans;

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
    while (cin >> n && n)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            ft[i] = 0;
            arr[i] = n - arr[i] + 1;
        }

        for (int i = 1; i <= n; i++)
        {
            ans += query(arr[i]);
            update(arr[i], 1);
        }

        cout << (ans % 2 ? "Marcelo" : "Carlos") << endl;
    }
}