#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define par pair<int, int>
#define MOD 1000000007
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, soma, a[109], memo[1000009], N;

int f(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + f(n - a[i])) % MOD;

    return memo[n] = (ans % MOD);
}

int main()
{_
    cin >> N >> soma;
    for (int i = 0; i <= soma + 1; i++)
        memo[i] = -1;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << f(soma) << endl;
}