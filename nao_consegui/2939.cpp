#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD (int) 1e9+7
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, dp[1000009];

int main()
{_
    cin >> n;
    dp[0] = 1, dp[1] = 2;
    for (long long i = 2; i <= n; i++)
    {
        dp[i] = (((i * dp[i - 1]) % MOD) * 2LL) % MOD;
        dp[i] = (dp[i] + (((((i * (i - 1)) % MOD) * 4LL) % MOD) * dp[i - 2]) % MOD) % MOD;
    }

    cout << dp[n] % MOD << endl;
}