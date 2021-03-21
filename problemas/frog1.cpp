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

int N, a[100009], memo[100009];

int f(int n)
{
    if (n < 2) return INF;
    if (n == 2) return 0;
    if (memo[n] != -1) return memo[n];
    return memo[n] = min(f(n - 1) + abs(a[n] - a[n - 1]), f(n - 2) + abs(a[n] - a[n - 2]));
}

int main()
{_
    cin >> N;
    for (int i = 2; i <= N + 1; i++)
    {
        memo[i] = -1;
        cin >> a[i]; 
    }

    cout << f(N + 1) << endl;
}