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

int a, b, c, d, e, f, ans;

int main()
{_
    cin >> a >> b >> c >> d >> e >> f;
    ans += max(0, d - a);
    ans += max(0, e - b);
    ans += max(0, f - c);
    cout << ans << endl;
}