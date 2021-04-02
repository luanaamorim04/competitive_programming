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

long long t, menor, maior, ans, memo[100009][51];

long long f(int atual, int tempo)
{
    if (atual < menor || atual > maior) return 0;
    if (tempo == t) return 1;
    if (memo[atual][tempo] != -1) return memo[atual][tempo];
    return memo[atual][tempo] = (f(atual + 1, tempo + 1) + (f(atual - 1, tempo + 1) % MOD)) % MOD;
}

int main()
{_
    cin >> t >> menor >> maior;
    for (int i = menor; i <= maior; i++)
        for (int j = 0; j <= t; j++)
            memo[i][j] = -1;

    for (int i = menor; i <= maior; i++)
        ans = (ans + f(i, 1)) % MOD;

    cout << ans << endl;
}