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

double n, media, x, y, ans;

int main()
{_
    cin >> n;
    ans = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        media = x / y;
        ans = min(ans, media);
    }

    ans *= 1000;

    cout << fixed << setprecision(2) << ans << endl;
}