#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{_
    int n, res = 1;
    cin >> n;
    int x[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    if (n <= 2)
    {
        cout << 1;
        return 0;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (x[i] - x[i - 1] != x[i + 1] - x[i]) res++;
    }

    cout << res << endl;

}