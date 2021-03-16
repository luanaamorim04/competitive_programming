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

long long n, p, q, r, s, x, y, a, b, ans;

int main()
{_  
    cin >> n >> p >> q >> r >> s >> x >> y >> a >> b;
    for (int i = 1; i <= n; i++)
        ans += ((p*a + q*i) % x) * ((r*i + s*b) % y);

    cout << ans << endl;
}