#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, rua[100009], ans;

int main()
{_
    ans = 1000000900;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> rua[i];
    }

    sort(rua, rua+n);
    k = n - k;
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, rua[k + i - 1] - rua[i]);
        //cout << rua[i] << ' ' << rua[k + i - 1] << ' ' << ans << endl;

    }
    cout << ans << endl;

}