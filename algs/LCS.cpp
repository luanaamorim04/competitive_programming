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
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int arr1[1009], arr2[1009], n, m, memo[1009][1009];

int f(int a, int b)
{
    if (a > n || b > m) return 0;
    if (memo[a][b] != -1) return memo[a][b];
    if (arr1[a] == arr2[b]) return memo[a][b] = 1 + f(a + 1, b + 1);
    return memo[a][b] = max(f(a + 1, b), f(a, b + 1));
}

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    
    for (int i = 1; i <= m; i++)
        cin >> arr2[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            memo[i][j] = -1;

    cout << n - f(1, 1) << ' ' << m - f(1, 1) << endl;
}