#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, d, x, y, ans, ok;
double k;
char c;

int main()
{_
    ok = 1;
    cin >> n >> m;
    while (n--)
    {
        cin >> c >> d;
        if (c == 'S') y -= d;
        else if (c == 'N') y += d;
        else if (c == 'O') x -= d;
        else if (c == 'L') x += d;
        ans = (x*x) + (y*y);
        k = sqrt(ans);
        if (k > m) ok = 0;

    }

    cout << (ok ? 0 : 1) << endl;
}