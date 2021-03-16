#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD (int) (1e9 + 7)

using namespace std;

int N, K, memo[1009][1009];

int f(int n, int k)
{
    if (k >= K || n > N) return 0;
    if (n == N) return 1;
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] = (f(n + 1, k + 1) + f(n + 1, 0)) % MOD;
}

int main()
{_
    cin >> N >> K;
    cout << f(0, 0) << endl;
}