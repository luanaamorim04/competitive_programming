#include <iostream>

using namespace std;

long long n, arr[21], ans, k;

long long f(long long a, long long b, int idx)
{
    if (idx == n) return abs(a - b);
    return min(f(a + arr[idx], b, idx + 1), f(a, b + arr[idx], idx + 1));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << f(0, 0, 0) << endl;
}   