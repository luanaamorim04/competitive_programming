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

int N, K, C, psa[10009], memo[10009][10009];

int f(int n, int e)
{
    if (!e) return 0;
    if (n + C - 1 > N) return INF;
    if (e*C > N - n + 1) return INF;
    if (memo[n][e]) return memo[n][e];
    return memo[n][e] = min(psa[n + C - 1] - psa[n - 1] + f(n + C, e - 1), f(n + 1, e));
}

int main()
{_
    cin >> N >> K >> C;

    for (int i = 1; i <= N; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }

    cout << psa[N] - f(1, K) << endl;
}