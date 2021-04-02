#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[500001];

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > ans) ans++;
    }

    cout << ans << endl;
}