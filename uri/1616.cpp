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

long long n, m, fat[1009], memo[1009][1009];

long long f(int b, int g)
{
    if (b == 0 || g == 0) return (!b && !g);
    if (memo[b][g] != -1) return memo[b][g];
    return memo[b][g] = ((g*f(b - 1, g) % MOD) + f(b - 1, g - 1)) % MOD;
}

int main()
{_  
    fat[0] = 1;
    for (int i = 1; i < 1001; i++)
        fat[i] = (fat[i - 1] * i) % MOD;
    
    while (cin >> n >> m && n)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                memo[i][j] = -1;

        cout << (f(n, m) * fat[m]) % MOD << endl;
    }
}