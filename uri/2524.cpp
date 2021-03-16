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

int n, m, a[1009], memo[1009][1009];
int f(int idx, int qnt)
{
    if (idx == m) return (qnt % n == 0 ? 0 : -INF);
    if (memo[idx][qnt] != -1) return memo[idx][qnt]; 
    return memo[idx][qnt] = max(f(idx + 1, (qnt + a[idx]) % n) + 1, f(idx + 1, qnt % n));
}

int main()
{_
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                memo[i][j] = -1;

        cout << f(0, 0) << endl;
    }
}