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

int n, m, a, b, c, d, memo[1009][1009];

int f(int a, int b)
{
    if (a == c && b == d) return 0;
    if (a > n || b > m || a < 1 || b < 1) return -INF;
    return max(max(f(a + 1, b), f(a - 1, b)), max(f(a, b + 1), f(a, b - 1))) + 1;
}

int main()
{_  
    cin >> n >> m >> a >> b >> c >> d;
    cout << f(a, b) << endl;
}