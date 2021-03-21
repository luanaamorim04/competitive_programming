#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long a, b, res, n, arr[200009];

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    a = arr[0]*arr[1]*arr[n - 1];
    b = arr[n - 3]*arr[n - 2]*arr[n - 1];
    res = max(a, b);
    cout << res;
}