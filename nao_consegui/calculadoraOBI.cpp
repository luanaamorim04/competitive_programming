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

long double ans, n, x;
char c;

int main()
{_
    cin >> n;
    ans = 1;
    while (n--)
    {
        cin >> x >> c;
        if (c == '*') ans = ans * x;
        else ans = ans / x;
    }

    cout << ans << endl;
}