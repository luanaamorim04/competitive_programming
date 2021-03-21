#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int atual, c, n, ans, tanque;

int main()
{_
    cin >> n >> c;
    if (n <= c) 
    {
        cout << n << endl;
        return 0;
    }
    ans = c; 
    for (int i = 2; i <= n - c + 1; i++)
    {
        ans += i;
    }

    cout << ans << endl;
}