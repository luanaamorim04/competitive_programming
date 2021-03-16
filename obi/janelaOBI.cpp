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

int a[3], ans;

int main()
{_  
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    ans = 60000;
    if (a[1] > a[0] + 200) 
    {
        ans -= 20000;
        ans -= ((a[2] + 200) - a[1])*100;
    }
    else if (a[2] > a[1] + 200)
    {
        ans -= 20000;
        ans -= ((a[1] + 200) - a[0])*100;
    }
    else
    {
        ans -= (a[2] + 200 - a[0])*100;
    }
    
    cout << ans << endl;
}