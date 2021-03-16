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

int n, x, a, b, ans;

int main()
{_  
    cin >> n;
    a = 4, b = 3;
    while (n--)
    {
        cin >> x;
        if (x == 1) a += 1, b += 2;
        if (x == 2) a += 2, b += 1;
        if (x == 3) a += 2, b -= 1;
        if (x == 4) a += 1, b -= 2;
        if (x == 5) a -= 1, b -= 2;
        if (x == 6) a -= 2, b -= 1;
        if (x == 7) a -= 2, b += 1;
        if (x == 8) a -= 1, b += 2;
        ans++;
        if (a == 1 && b == 3) break;
        if (a == 2 && b == 3) break;
        if (a == 2 && b == 5) break;
        if (a == 5 && b == 4) break;
    }
    
    cout << ans << endl;
}