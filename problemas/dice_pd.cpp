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

int memo[1000009], N;

long long f(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    long long ans = 0;
    for (int i = 1; i <= 6; i++)
        ans = (ans + f(n - i)) % MOD;
    return memo[n] = ans % MOD;
}

int main()
{_
    cin >> N;
    for (int i = 0; i <= N; i++)
        memo[i] = -1;
    cout << f(N) << endl;
}