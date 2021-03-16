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
#define lsb(x) (x & -x)
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int arr[100009], ft[100009], n, idx;
char c;

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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (cin >> c >> idx)
    {
        if (c == 'a') update(idx, -arr[idx]);
        else cout << query(idx - 1) << endl;
    }
}