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

int N, a[200009], memo[200009][2];

int f(int n, int x)
{
    if (n > N || n < 1) return 0;
    if (memo[n][x] !=  -INF) return memo[n][x];
    return memo[n][x] = max(2*a[n] - (x ? a[n - 1] : 0) - a[n + 1] + f(n + 2, 0), f(n + 1, 1));
}

int main()
{_
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        memo[i][0] = -INF;
        memo[i][1] = -INF;
    }

    cout << f(1, 0) << endl;
}