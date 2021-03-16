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

int n, ans, a[100001];

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ans = -INF;
    for (int i = 0; i < n - 3; i++)
        ans = max(ans, a[i] + a[i + 1] + a[i + 2] + a[i + 3]);

    cout << ans << endl;
}