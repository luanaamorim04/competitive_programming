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
 
int arr[MAXN], maxn, n, memo[109][MAXN];
 
int f(int last, int idx)
{
    if (memo[last][idx] != -1) return memo[last][idx];
    if (arr[idx] && abs(last - arr[idx]) > 1) return 0;
    if (arr[idx]) return memo[last][idx] = f(arr[idx], idx + 1);
    int ans = 0;
    if (last) ans = f(last, idx + 1);
    if (last < maxn) ans = (ans + f(last + 1, idx + 1)) % MOD;
    if (last > 1) ans = (ans + f(last - 1, idx + 1)) % MOD;
    return memo[last][idx] = ans;
}
 
int main()
{
    cin >> n >> maxn;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
 
    for (int i = 0; i <= maxn; i++)
        for (int j = 0; j <= n; j++)
            memo[i][j] = j != n ? -1 : 1;

    if (!arr[0])
    {
        int ans = 0;
        for (int i = 1; i <= maxn; i++)
            ans = (ans + f(i, 1)) % MOD;
        cout << ans << endl;
        return 0;
    }
 
    cout << f(arr[0], 0) << endl;
}