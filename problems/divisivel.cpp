#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long n, sum, a, ans;
map<int, int> k;

int main()
{_
    k[0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum = ((sum % 8) + (a % 8) + 8) % 8;
        ans += k[sum];
        k[sum]++;
    }

    cout << ans << endl;
}