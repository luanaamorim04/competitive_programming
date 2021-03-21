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

int dp[100009], v[1009], p[1009], soma, n;

int main()
{_  
    cin >> n >> soma;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        for (int j = soma; j >= p[i]; j--)
            dp[j] = max(dp[j], v[i] + dp[j - p[i]]);

    cout << dp[soma] << endl;
}