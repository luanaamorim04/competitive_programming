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

string a, b;
int memo[55][55], N;

int f(int x, int y)
{
    if (x >= a.size() || y >= b.size()) return 0;
    if (memo[x][y] != -1) return memo[x][y];
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (x + i >= a.size() || y + i >= b.size()) break;
        if (a[x + i] != b[y + i]) break;
        ++ans;
    }

    return memo[x][y] = max(ans, max(f(x + 1, y), f(x, y + 1)));
}

int main()
{_  
    while (getline(cin, a) && getline(cin, b))
    {
        N = max(a.size(), b.size());
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                memo[i][j] = -1;

        cout << f(0, 0) << endl;
    }
}