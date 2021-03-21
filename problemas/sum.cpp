#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long n, sum[200005], q, a, ans;
map<long long, int> k;

int main()
{_
    sum[0] = 0;
    k[0]++;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum[i] = sum[i - 1] + a;
        ans += k[sum[i]-q];
        k[sum[i]]++;
    }

    cout << ans << endl;

}