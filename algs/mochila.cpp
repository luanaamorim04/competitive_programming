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

long long peso, n, p[2009], v[2009], dp[200009];

int main()
{_
    cin >> n >> peso;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> v[i];

    for (int j = 1; j <= n; j++)
        for (int i = peso; i >= p[j]; i--)
            dp[i] = max(dp[i], dp[i - p[j]] + v[j]);

    cout << dp[peso] << endl;
}