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

long long n, k, a[101], memo[101][100009];

long long f(int idx, int total)
{
    if (idx > n) return !total;
    if (total < 0) return 0;
    if (memo[idx][total] != -1) return memo[idx][total];

    long long ans = 0;
    for (int i = 0; i <= a[idx]; i++)
        ans = (ans + f(idx + 1, total - i)) % MOD;
    return memo[idx][total] = ans;
}

int main()
{_  
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            memo[i][j] = -1;

    cout << f(1, k) << endl;
}