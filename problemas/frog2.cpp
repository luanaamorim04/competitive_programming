#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long N, a[100109], memo[100109], k;

long long f(int n)
{
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    long long ans = INF;
    for (int i = 1; i <= k; i++)
    {
        if (n - i < 1) continue;
        ans = min(ans, f(n - i) + abs(a[n] - a[n - i]));
    }
    return memo[n] = ans;
}

int main()
{_
    cin >> N >> k;
    for (int i = 1; i <= N; i++)
    {
        memo[i] = -1;
        cin >> a[i]; 
    }

    cout << f(N) << endl;
}