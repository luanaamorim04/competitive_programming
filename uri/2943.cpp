#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#include <string.h>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e6
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ft[1000009], arr[1009], n, esq[1009], ans;

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
    while (idx <= MAXN)
    {
        ft[idx] = max(ft[idx], val);
        idx += lsb(idx);
    }
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        esq[i] = query(arr[i] - 1);
        update(arr[i], esq[i] + 1);
    }

    memset(ft, 0, sizeof(ft));

    for (int i = n - 1; i >= 0; i--)
    {
        ans = max(ans, esq[i] + query(arr[i] - 1));
        update(arr[i], query(arr[i] - 1) + 1);
    }

    cout << ans << endl;
}