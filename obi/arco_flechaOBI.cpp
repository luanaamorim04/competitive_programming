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

long long arr[300009], a[100009], ans, ft[300009], A, b, n;
map<long long, int> mapa;

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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A >> b;
        arr[i+1] = (A*A) + (b*b);
        a[i] = arr[i+1];
    }

    sort(a, a+n);

    for (int i = 0; i < n; i++)
    {
        mapa[a[i]] = i+1;
    }

    for (int i = 1; i <= n; i++)
    {
        ans += query(mapa[arr[i]]);
        update(mapa[arr[i]], 1);
    }

    cout << ans << endl;
}