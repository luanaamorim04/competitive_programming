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

long long n, memo[1009][1009];
int g, h;
char c;

int f(int a, int b)
{   
    if (memo[a][b] != -1) return memo[a][b];
    if (a == n && b == n) return 1;
    return memo[a][b] = (f(a + 1, b) + f(a, b + 1)) % MOD;
}   

int main()
{_  
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '.')
            {
                memo[i][j] = -1;
            } 
        }
    }

    cout << f(1, 1) << endl;
}