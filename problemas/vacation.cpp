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

int N, a[100009][3], memo[1000009][4];

int f(int n, int k)
{
    if (n > N) return 0;
    if (memo[n][k] != -1) return memo[n][k];
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (k == i) continue;
        ans = max(ans, a[n][i] + f(n + 1, i));
    }

    return memo[n][k] = ans;
}

int main()
{_
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        memo[i][0] = -1; memo[i][1] = -1; memo[i][2] = -1;
    }

    memo[0][3] = -1;

    cout << f(0, 3) << endl;
}