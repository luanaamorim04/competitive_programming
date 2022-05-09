#include <iostream>
#include <algorithm>

using namespace std;

int ans, n, t, arr[101];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        for (int i = 1; i < n; i++)
            if (arr[i] == arr[i - 1] + 1) 
                ans = 2;

        cout << ans << endl;
    }
}