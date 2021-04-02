#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[9];

int main()
{_
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);

        do
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
        while (next_permutation(arr, arr+n));
        cout << endl;
    }
}