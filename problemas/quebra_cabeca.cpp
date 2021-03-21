#include <iostream>
#include <algorithm>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{_
    int n, num[1003];
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num, num+n);

    for (int i = 1; i <= n; i++)
    {
        if (num[i] != i)
        {
            cout << i << endl;
            return 0;
        }
    }
}