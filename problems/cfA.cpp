#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, num, dig, ans;

int f(int n)
{
    int ans = 0;
    while (n)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> num;
        ans = ((num % 10) - 1)*10;
        for (int i = 1; i <= f(num); i++) ans += i;
        cout << ans << endl;
    }
}