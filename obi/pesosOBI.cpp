#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[100009];

int main()
{_
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n+1);

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] - arr[i - 1] > 8)
        {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}