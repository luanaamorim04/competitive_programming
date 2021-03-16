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

int n, m, x, y, k, a, b, z, ans;

int main()
{_
    cin >> n >> m >> x >> y;
    cin >> k;
    while (k--)
    {
        cin >> z;
        if (z == 1) b++;
        if (z == 2) b--;
        if (z == 3) a++;
        if (z == 4) a--;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                ans += (a == x + i && b == y + j);
    }

    cout << ans << endl;
}