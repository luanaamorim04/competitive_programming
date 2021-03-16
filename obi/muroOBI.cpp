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

long long memo[10009], n;

long long f(int n)
{
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];
    return memo[n] = (f(n - 1) % MOD + ((4 * f(n - 2)) % MOD) + (2 * f(n - 3))) % MOD;
}

int main()
{_
    cin >> n;
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    cout << f(n) << endl;
}