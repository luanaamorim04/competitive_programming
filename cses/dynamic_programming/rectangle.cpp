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

int memo[1009][1009], a, b;


int f(int a, int b)
{   
    if (a == b) return 1;
    if (memo[a][b] != -1) return memo[a][b];
    int ans = INF;
    for (int i = 1; i <= a/2; i++)
        ans = min(ans, f(a - i, b) + f(i, b));
    for (int i = 1; i <= b/2; i++)
        ans = min(ans, f(a, b - i) + f(a, i));

    return memo[a][b] = ans;
}   

int main()
{_  
    cin >> a >> b;
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++)
            memo[i][j] = -1;

    cout << f(a, b) - 1 << endl;
}