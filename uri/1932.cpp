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

int N, C, a[200009], dp[2000009][2];

int main()
{_
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
        cin >> a[i]; 

    for (int i = N; i >= 1; i--)
    {
        dp[i][0] = max(dp[i + 1][1] - a[i] - C, dp[i + 1][0]);
        dp[i][1] = max(dp[i + 1][0] + a[i], dp[i + 1][1]);
    }

    cout << dp[1][0] << endl;
}