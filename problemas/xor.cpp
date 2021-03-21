#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, sum[200005], q, a, b;

int main()
{_
    sum[0] = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum[i] = sum[i - 1]^a;
    }

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << (sum[a-1]^sum[b]) << endl;
    }
}