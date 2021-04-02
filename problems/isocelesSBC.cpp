#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int e[MAXN], d[MAXN], ans, n, arr[MAXN], h;

int main()
{_  
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        e[i] = e[i - 1];
        if (arr[i] > e[i]) e[i]++;
        else if (arr[i] < e[i]) e[i] = arr[i];
    }

    for (int i = n; i >= 1; i--)
    {
        d[i] = d[i + 1];
        if (arr[i] > d[i]) d[i]++;
        else if (arr[i] < d[i])
            d[i] = arr[i];

        ans = max(ans, min(d[i], e[i]));
    }
    
    cout << ans << endl;
}