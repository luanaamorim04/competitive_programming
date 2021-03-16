#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#include <string.h>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, memo[22][22], i, ans;
string dic[1001], s;

int f(int a, int b)
{
    if (a < 0) return b + 1;
    if (b < 0) return a + 1;
    if (memo[a][b] != -1) return memo[a][b];
    if (dic[i][a] == s[b]) return f(a - 1, b - 1);
    return memo[a][b] = min(f(a - 1, b - 1), min(f(a - 1, b), f(a, b - 1))) + 1;
}

int main()
{_  
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> dic[i];

    for (int j = 0; j < m; j++)
    {
        cin >> s;
        for (i = 0; i < n; i++)
        {
            memset(memo, -1, sizeof(memo));
            ans = f(dic[i].size(), s.size());
            if (ans <= 2) cout << dic[i] << ' ';
        }
        cout << endl << endl;
    }
}