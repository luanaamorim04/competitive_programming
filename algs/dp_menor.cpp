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

int N, memo[1000009];

int f(int n)
{
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    int x = n, ans = INF, dig;
    while (x > 0)
    {
        dig = x % 10;
        if (dig != 0)
            ans = min(ans, 1 + f(n - dig));
        x /= 10;
    }

    return memo[n] = ans;
}

int main()
{_
    cin >> N;
    for (int i = 0; i <= N; i++)
        memo[i] = -1;

    cout << f(N) << endl;
}