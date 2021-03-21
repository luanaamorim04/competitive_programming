#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long n, a, ans, sum;
map<long long, int> f;

int main()
{_
    cin >> n;
    f[0]++;
    while (n--)
    {
        cin >> a;
        sum += a;
        ans += f[sum];
        f[sum]++;
    }

    cout << ans << '\n';
}