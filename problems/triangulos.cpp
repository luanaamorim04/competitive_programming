#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[MAXN];

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for (int i = n - 3; i >= 0; i--)
    {
        if (arr[i + 2] < arr[i + 1] + arr[i])
        {
            cout << arr[i] << ' ' << arr[i + 1] << ' ' << arr[i + 2] << endl;
            return 0;
        }
    }
}