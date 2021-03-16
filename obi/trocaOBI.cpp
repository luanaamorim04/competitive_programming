#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, psa[100005], arr[100005][2], a, b;

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n*2; i++)
    {
        cin >> (i < n ? arr[i][0] : arr[i - n][1]);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        psa[a]++;
        psa[b + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        psa[i] = psa[i - 1] + psa[i];
        cout << (psa[i] % 2 ? arr[i - 1][1] : arr[i - 1][0]) << ' ';
    }

}