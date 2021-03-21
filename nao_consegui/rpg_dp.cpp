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

int memo[3][10001][501], n, m, p[10001], v[10001], l[10001];

int f(int at, int idx, int peso)
{
    if (peso < 0 || at > 2) return -INF;
    if (memo[at][idx][peso] != -1) return memo[at][idx][peso];
    return memo[at][idx][peso] = max(max(f(at, idx + 1, peso - p[idx]) + v[idx], f(at, idx + 1, peso)),
    max(f(at + 1, idx + 1, peso + l[idx]), f(at + 1, idx + 1, peso + l[idx] - p[idx]) + v[idx]));
}

int main()
{_  
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> p[i] >> l[i];

    for (int i = 0; i <= 2; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= m; k++)
                memo[i][j][k] = -1;

    cout << f(0, 0, m) << endl;
}