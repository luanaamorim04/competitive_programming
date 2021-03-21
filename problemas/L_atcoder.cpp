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

long long memo[3001][3001], soma, n, arr[3001], ans, x, y;

long long f(int l, int r)
{
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    return memo[l][r] = max(arr[l] + min(f(l + 2, r), f(l + 1, r - 1)), arr[r] + min(f(l + 1, r - 1), f(l, r - 2)));
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        soma += arr[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;

    x = f(0, n - 1);
    y = soma - x;
    ans = x - y;
    cout << ans << endl;
}