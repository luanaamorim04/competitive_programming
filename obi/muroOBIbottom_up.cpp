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
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, dp[10009];

int main()
{_
    cin >> n;
    dp[0] = 1; dp[1] = 1; dp[2] = 5;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + 4*dp[i-2] + 2*dp[i-3]) % MOD;

    cout << dp[n] << endl;
}